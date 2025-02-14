#if defined(DM_PLATFORM_HTML5)
#include "bridge_leaderboards.h"
#include "bridge.h"

int bridge::leaderboards::isSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isSupported);
}

int bridge::leaderboards::isNativePopupSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isNativePopupSupported);
}

int bridge::leaderboards::isMultipleBoardsSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isMultipleBoardsSupported);
}

int bridge::leaderboards::isSetScoreSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isSetScoreSupported);
}

int bridge::leaderboards::isGetScoreSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isGetScoreSupported);
}

int bridge::leaderboards::isGetEntriesSupported(lua_State* L) {
    return boolGetter(L, js_bridge_leaderboard_isGetEntriesSupported);
}

int bridge::leaderboards::setScore(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_leaderboard_setScore, false);
}

int bridge::leaderboards::getScore(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_leaderboard_getScore, true);
}

int bridge::leaderboards::getEntries(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_leaderboard_getEntries, true);
}

int bridge::leaderboards::showNativePopup(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_leaderboard_showNativePopup, false);
}

#endif