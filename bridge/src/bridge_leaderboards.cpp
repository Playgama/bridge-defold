#if defined(DM_PLATFORM_HTML5)
#include "bridge_leaderboards.h"
#include "bridge.h"

int bridge::leaderboards::type(lua_State* L) {
    return getString(L, js_bridge_leaderboards_type);
}

int bridge::leaderboards::setScore(lua_State* L) {
    return makeCallbackLeaderboardsSetScore(L, js_bridge_leaderboards_setScore, false);
}

int bridge::leaderboards::getEntries(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_leaderboards_getEntries, true);
}

#endif