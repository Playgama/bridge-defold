// myextension.cpp
// Extension lib defines
#define LIB_NAME "Bridge"
#define MODULE_NAME "Bridge"

// include the Defold SDK

#if defined(DM_PLATFORM_HTML5)
    #include "bridge_platform.h"
#endif
#include <stdio.h>

#include "bridge.h"

static int platformID(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::id();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_payload(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::payload();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_tld(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::tld();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_getServerTime(lua_State* L)
{
    int top = lua_gettop(L);
    dmScript::LuaCallbackInfo *onSuccess = NULL;
    dmScript::LuaCallbackInfo *onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 1);
    onFailure = dmScript::CreateCallback(L, 2);

    bridge::platform::getServerTime(onSuccess, onFailure);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_platform_sendMessage(lua_State* L)
{
    int top = lua_gettop(L);
    size_t len;
    const char* event = luaL_checklstring(L, 1, &len);
    dmScript::LuaCallbackInfo *onSuccess = NULL;
    dmScript::LuaCallbackInfo *onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);
    onFailure = dmScript::CreateCallback(L, 3);

    bridge::platform::sendMessage(event, onSuccess, onFailure);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_game_on(lua_State* L)
{
    int top = lua_gettop(L);
    dmScript::LuaCallbackInfo *callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);

    bridge::game::on(event_name, callback);
    assert(top == lua_gettop(L));
    return 0;
}


// Functions exposed to Lua
static const luaL_reg platforms_methods[] =
{
    {"id", platformID},
    {"sendMessage", bridge_platform_sendMessage},
    {"getServerTime", bridge_platform_getServerTime},
    {"payload", bridge_platform_payload},
    {"tld", bridge_platform_tld},
    {0, 0}
};

static const luaL_reg game_methods[] =
{
    {"on", bridge_game_on},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    int top = lua_gettop(L);

    lua_newtable(L); // Создаем таблицу bridge
    lua_pushvalue(L, -1); // Копируем таблицу bridge на вершину стека
    lua_setglobal(L, "bridge"); // Устанавливаем таблицу bridge как глобальную переменную

    lua_pushstring(L, "platform"); // create platform table
    lua_newtable(L);
    luaL_register(L, NULL, platforms_methods);
    lua_settable(L, -3);


    lua_pushstring(L, "game"); // create platform table
    lua_newtable(L);
    luaL_register(L, NULL, game_methods);
    lua_settable(L, -3);


    lua_pop(L, 1);

    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeMyExtension(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeMyExtension(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    printf("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeMyExtension(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeMyExtension(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}


// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

// MyExtension is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(Bridge, LIB_NAME, AppInitializeMyExtension, AppFinalizeMyExtension, InitializeMyExtension, 0, 0, FinalizeMyExtension)