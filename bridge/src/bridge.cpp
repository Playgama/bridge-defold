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
#if defined(DM_PLATFORM_HTML5)
#pragma region Platform
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
    DM_LUA_STACK_CHECK(L, 0);
    if (!lua_isfunction(L, 1)) {
        dmLogError("get_server_time");
        return 0;
    }
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 1);
    if (lua_isfunction(L, 1) || lua_isnil(L, 1))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::platform::getServerTime(onSuccess, onFailure);

    return 0;
}

static int bridge_platform_sendMessage(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    size_t len;
    const char* event = luaL_checklstring(L, 1, &len);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);
    onFailure = dmScript::CreateCallback(L, 3);

    bridge::platform::sendMessage(event, onSuccess, onFailure);
    return 0;
}
#pragma endregion

#pragma region Game
static int bridge_game_on(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);

    bridge::game::on(event_name, callback);
    return 0;
}

static int bridge_game_visibilityState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::game::visibilityState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}
#pragma endregion

#pragma region Storage
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
    DM_LUA_STACK_CHECK(L, 0);
    // const char* key = luaL_checkstring(L, 1);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::get(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}

static int bridge_storage_set(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    // assert(res < 0);

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::set(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}

static int bridege_storage_delete(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::deleteData(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}
#pragma endregion

#pragma region Advertisement
static int bridege_advertisement_showBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    bridge::advertisement::showBanner(json);
    free(json);
    return 0;
}

static int bridege_advertisement_hideBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::hideBanner();
    return 0;
}

static int bridge_advertisement_bannerState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::bannerState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_isBannerSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isAvailable = bridge::advertisement::isBannerSupported();
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_advertisement_on(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);
    bridge::advertisement::on(event_name, callback);
    return 0;
}

static int bridge_advertisement_showInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::showInterstitial();
    return 0;
}

static int bridge_advertisement_minimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    int delay = bridge::advertisement::minimumDelayBetweenInterstitial();
    lua_pushinteger(L, delay);
    return 1;
}

static int bridge_advertisement_setMinimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    int delay = luaL_checkinteger(L, 1);
    bridge::advertisement::setMinimumDelayBetweenInterstitial(delay);
    return 0;
}

static int bridge_advertisement_interstitialState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::interstitialState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_rewardedState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::rewardedState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_showRewarded(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::showRewarded();
    return 0;
}

static int bridge_advertisement_checkAdBlock(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::advertisement::checkAdBlock(onSuccess, onFailure);
    return 0;
}

#pragma endregion
// Functions exposed to Lua
static const luaL_reg platform_methods[] = {
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
    { "is_available", bridge_storage_isAvailable },
    { "get", bridge_storage_get },
    { "set", bridge_storage_set },
    { "delete", bridege_storage_delete },
    { 0, 0 }
};

static const luaL_reg advertisement_methods[] = {
    // Banner
    { "show_banner", bridege_advertisement_showBanner },
    { "hide_banner", bridege_advertisement_hideBanner },
    { "banner_state", bridge_advertisement_bannerState },
    { "is_banner_supported", bridge_advertisement_isBannerSupported },
    { "on", bridge_advertisement_on },

    // Interstitial
    { "show_interstitial", bridge_advertisement_showInterstitial },
    { "minimum_delay_between_interstitial", bridge_advertisement_minimumDelayBetweenInterstitial },
    { "set_minimum_delay_between_interstitial", bridge_advertisement_setMinimumDelayBetweenInterstitial },
    { "interstitial_state", bridge_advertisement_interstitialState },

    // Rewarded
    { "rewarded_state", bridge_advertisement_rewardedState },
    { "show_rewarded", bridge_advertisement_showRewarded },
    { "check_ad_block", bridge_advertisement_checkAdBlock },
    { 0, 0 }
};

#endif

#pragma region Defold
static void LuaInit(lua_State* L) {
    int top = lua_gettop(L);
#if defined(DM_PLATFORM_HTML5)

    lua_newtable(L); // create bridge table (root)
    lua_pushvalue(L, -1);
    lua_setglobal(
        L, "bridge");
    {
        lua_pushstring(L, "platform"); // create platform table
        lua_newtable(L);
        luaL_register(L, NULL, platform_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "game"); // create game table
        lua_newtable(L);
        luaL_register(L, NULL, game_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "storage"); // create storage table
        lua_newtable(L);
        luaL_register(L, NULL, store_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "advertisement"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, advertisement_methods);
        lua_settable(L, -3);
    }
    lua_pop(L, 1);
#endif
    // if(luaL_dostring(L, "bridge = require \"bridge.res.common.bridge_mock\"") != 0) {
    //     dmLogError("%s", lua_tostring(L, -1));
    // }
    // lua_pop(L, 1);
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
#pragma endregion
DM_DECLARE_EXTENSION(Bridge, LIB_NAME, AppInitializeMyExtension,
                     AppFinalizeMyExtension, InitializeMyExtension, 0, 0,
                     FinalizeMyExtension)