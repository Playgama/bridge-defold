#if defined(DM_PLATFORM_HTML5)
#include "bridge_remote_config.h"
#include "bridge.h"

int bridge::remoteConfig::isSupported(lua_State* L) {
    return getBoolean(L, js_bridge_remoteConfig_isSupported);
}

int bridge::remoteConfig::setDynamicParameters(lua_State* L) {
    return callWithJson(L, js_bridge_remoteConfig_setDynamicParameters);
}

int bridge::remoteConfig::get(lua_State* L) {
    return makeCallback(L, js_bridge_remoteConfig_get, true);
}

#endif