#if defined(DM_PLATFORM_HTML5)
#include "bridge_platform.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::platform::on(lua_State* L) {
    return makeOnCallback(L, js_bridge_platform_on);
}

int bridge::platform::id(lua_State* L) {
    return getString(L, js_bridge_platform_id);
}

int bridge::platform::language(lua_State* L) {
    return getString(L, js_bridge_platform_language);
}

int bridge::platform::tld(lua_State* L) {
    return getString(L, js_bridge_platform_tld);
}

int bridge::platform::payload(lua_State* L) {
    return getString(L, js_bridge_platform_payload);
}

int bridge::platform::getServerTime(lua_State* L) {
    return makeCallback(L, js_bridge_platform_getServerTime, true);
}

int bridge::platform::sendMessage(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    size_t len;
    const char* message = luaL_checklstring(L, 1, &len);
    char* json = NULL;

    int callbackIndex = 2;
    if (lua_istable(L, 2)) {
        size_t json_len;
        lua_pushvalue(L, 2);
        lua_replace(L, 1);
        dmScript::LuaToJson(L, &json, &json_len);
        callbackIndex = 3;
    }

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, callbackIndex))
        onSuccess = dmScript::CreateCallback(L, callbackIndex);

    if (lua_isfunction(L, callbackIndex + 1))
        onFailure = dmScript::CreateCallback(L, callbackIndex + 1);

    js_bridge_platform_sendMessage((UniversalHandler)cppUniversalHandler, message, json, onSuccess, onFailure);

    if (json) {
        free(json);
    }

    return 0;
}

int bridge::platform::isAudioEnabled(lua_State* L) {
    return getBoolean(L, js_bridge_platform_isAudioEnabled);
}

int bridge::platform::isGetAllGamesSupported(lua_State* L) {
    return getBoolean(L, js_bridge_platform_isGetAllGamesSupported);
}

int bridge::platform::getAllGames(lua_State* L) {
    return makeCallback(L, js_bridge_platform_getAllGames, false);
}

int bridge::platform::isGetGameByIdSupported(lua_State* L) {
    return getBoolean(L, js_bridge_platform_isGetGameByIdSupported);
}

int bridge::platform::getGameById(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_platform_getGameById, false);
}

#endif