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
    return makeCallbackWithString(L, js_bridge_platform_sendMessage, false);
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