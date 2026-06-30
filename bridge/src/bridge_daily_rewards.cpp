#if defined(DM_PLATFORM_HTML5)
#include "bridge_daily_rewards.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::dailyRewards::getRewards(lua_State* L) {
    return makeCallback(L, js_bridge_daily_rewards_getRewards, true);
}

int bridge::dailyRewards::getCurrentDay(lua_State* L) {
    return makeCallback(L, js_bridge_daily_rewards_getCurrentDay, true);
}

int bridge::dailyRewards::getCurrentReward(lua_State* L) {
    return makeCallback(L, js_bridge_daily_rewards_getCurrentReward, true);
}

int bridge::dailyRewards::claimCurrentReward(lua_State* L) {
    return makeCallback(L, js_bridge_daily_rewards_claimCurrentReward, true);
}

#endif
