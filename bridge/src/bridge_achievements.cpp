#if defined(DM_PLATFORM_HTML5)
#include "bridge_achievements.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::achievements::unlock(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_achievements_unlock, true);
}

int bridge::achievements::getAchievements(lua_State* L) {
    return makeCallback(L, js_bridge_achievements_getAchievements, true);
}

#endif