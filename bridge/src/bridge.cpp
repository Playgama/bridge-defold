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
#include <dmsdk/dlib/crypt.h>

namespace dmScript {
    char* Sys_SetupTableSerializationBuffer(int required_size);
    void Sys_FreeTableSerializationBuffer(char* buffer);
}

static int bridge_platform_id(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::id();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_payload(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::payload();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_language(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::language();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_tld(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::platform::tld();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_platform_getServerTime(lua_State* L) {
    int top = lua_gettop(L);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 1);
    onFailure = dmScript::CreateCallback(L, 2);

    bridge::platform::getServerTime(onSuccess, onFailure);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_platform_sendMessage(lua_State* L) {
    int top = lua_gettop(L);
    size_t len;
    const char* event = luaL_checklstring(L, 1, &len);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);
    onFailure = dmScript::CreateCallback(L, 3);

    bridge::platform::sendMessage(event, onSuccess, onFailure);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_game_on(lua_State* L) {
    int top = lua_gettop(L);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);

    bridge::game::on(event_name, callback);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_game_visibilityState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::game::visibilityState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_storage_isAvailable(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    const char* storageType = luaL_checkstring(L, 1);
    bool isAvailable = bridge::storage::isAvailable(storageType);
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_storage_defaultType(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* defaultType = bridge::storage::defaultType();
    lua_pushstring(L, defaultType);
    free(defaultType);
    return 1;
}

static int bridge_storage_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    const char* storageType = luaL_checkstring(L, 1);
    bool isAvailable = bridge::storage::isSupported(storageType);
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_storage_get(lua_State* L) {
    int top = lua_gettop(L);
    const char* key = luaL_checkstring(L, 1);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::get(key, onSuccess, onFailure, storageType);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridge_storage_set(lua_State* L) {
    int top = lua_gettop(L);
    const char* key = luaL_checkstring(L, 1); // first key

    luaL_checktype(L, 2, LUA_TTABLE); // table
    uint32_t table_size = dmScript::CheckTableSize(L, 2);
    char* buffer = dmScript::Sys_SetupTableSerializationBuffer(table_size);
    if (!buffer) {
        return luaL_error(L, "Could not allocate %d bytes for table serialization.", table_size);
    }

    uint32_t n_used = dmScript::CheckTable(L, buffer, table_size, 2);

    uint32_t dstlen = table_size * 4 / 3 + 4;
    uint8_t* dst = (uint8_t*)malloc(dstlen);
    if (!dmCrypt::Base64Encode((uint8_t*)buffer, table_size, dst, &dstlen)) {
        free(dst);
        return luaL_error(L, "Can't encode data into Base64 string.");
    }
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 3))
        onSuccess = dmScript::CreateCallback(L, 3);

    if (lua_isfunction(L, 4))
        onFailure = dmScript::CreateCallback(L, 4);

    if (lua_isstring(L, 5))
        storageType = lua_tostring(L, 5);

    bridge::storage::set(key, (const char*)dst, onSuccess, onFailure, storageType);
    free(dst);
    dmScript::Sys_FreeTableSerializationBuffer(buffer);
    assert(top == lua_gettop(L));
    return 0;
}

static int bridege_storage_delete(lua_State* L) {
    int top = lua_gettop(L);
    const char* key = luaL_checkstring(L, 1);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::deleteData(key, onSuccess, onFailure, storageType);
    assert(top == lua_gettop(L));
    return 0;
}

// Functions exposed to Lua
static const luaL_reg platforms_methods[] = {
    { "id", bridge_platform_id },
    { "language", bridge_platform_language },
    { "payload", bridge_platform_payload },
    { "tld", bridge_platform_tld },
    { "send_message", bridge_platform_sendMessage },
    { "get_server_time", bridge_platform_getServerTime },
    { 0, 0 }
};

static const luaL_reg game_methods[] = {
    { "on", bridge_game_on },
    { "visibility_state", bridge_game_visibilityState },
    { 0, 0 }
};

static const luaL_reg store_methods[] = {
    { "default_type", bridge_storage_defaultType },
    { "is_supported", bridge_storage_isSupported },
    { "is_svailable", bridge_storage_isAvailable },
    { "get", bridge_storage_get },
    { "set", bridge_storage_set },
    { "delete", bridege_storage_delete },
    { 0, 0 }
};

static void LuaInit(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    int top = lua_gettop(L);

    lua_newtable(L); // create bridge table (root)
    lua_pushvalue(L, -1);
    lua_setglobal(
        L, "bridge");

    lua_pushstring(L, "platform"); // create platform table
    lua_newtable(L);
    luaL_register(L, NULL, platforms_methods);
    lua_settable(L, -3);

    lua_pushstring(L, "game"); // create game table
    lua_newtable(L);
    luaL_register(L, NULL, game_methods);
    lua_settable(L, -3);

    lua_pushstring(L, "storage"); // create storage table
    lua_newtable(L);
    luaL_register(L, NULL, store_methods);
    lua_settable(L, -3);

    lua_pop(L, 1);

    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeMyExtension(dmExtension::AppParams* params) {
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeMyExtension(dmExtension::Params* params) {
    // Init LuaÍ
    LuaInit(params->m_L);
    printf("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeMyExtension(dmExtension::AppParams* params) {
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeMyExtension(dmExtension::Params* params) {
    return dmExtension::RESULT_OK;
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update,
// on_event, final)

// MyExtension is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(Bridge, LIB_NAME, AppInitializeMyExtension,
                     AppFinalizeMyExtension, InitializeMyExtension, 0, 0,
                     FinalizeMyExtension)