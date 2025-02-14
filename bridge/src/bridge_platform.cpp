#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_helper.h"
#include "bridge_platform.h"

int bridge::platform::id(lua_State* L) {
    return stringGetter(L, js_bridge_platform_id);
}

int bridge::platform::language(lua_State* L) {
    return stringGetter(L, js_bridge_platform_language);
}

int bridge::platform::tld(lua_State* L) {
    return stringGetter(L, js_bridge_platform_tld);
}

int bridge::platform::payload(lua_State* L) {
    return stringGetter(L, js_bridge_platform_payload);
}

int bridge::platform::getServerTime(lua_State* L) {
    return voidCallbacksGetter(L, js_bridge_platform_getServerTime, true);
}

int bridge::platform::sendMessage(lua_State* L) {
    return voidStringCallbacksGetter(L, js_bridge_platform_sendMessage, false);
}

#endif