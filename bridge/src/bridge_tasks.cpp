#if defined(DM_PLATFORM_HTML5)
#include "bridge_tasks.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::tasks::getTasks(lua_State* L) {
    return makeCallback(L, js_bridge_tasks_getTasks, true);
}

int bridge::tasks::addProgress(lua_State* L) {
    // metric (string) + amount (int): reuse the shared string+int callback helper.
    return makeCallbackLeaderboardsSetScore(L, js_bridge_tasks_addProgress, true);
}

int bridge::tasks::claimReward(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_tasks_claimReward, true);
}

#endif
