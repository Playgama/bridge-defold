#if defined(DM_PLATFORM_HTML5)
#include "bridge_achievements.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::achievements::isSupported(lua_State* L) {
    return getBoolean(L, js_bridge_achievements_isSupported);
}

int bridge::achievements::unlock(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_achievements_unlock, true);
}

int bridge::achievements::getList(lua_State* L) {
    return makeCallback(L, js_bridge_achievements_getList, true);
}

#endif