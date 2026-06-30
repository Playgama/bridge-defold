#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    void js_bridge_daily_rewards_getRewards(UniversalHandler handler,
                                            dmScript::LuaCallbackInfo* onSuccess,
                                            dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_daily_rewards_getCurrentDay(UniversalHandler handler,
                                               dmScript::LuaCallbackInfo* onSuccess,
                                               dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_daily_rewards_getCurrentReward(UniversalHandler handler,
                                                  dmScript::LuaCallbackInfo* onSuccess,
                                                  dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_daily_rewards_claimCurrentReward(UniversalHandler handler,
                                                    dmScript::LuaCallbackInfo* onSuccess,
                                                    dmScript::LuaCallbackInfo* onFailure);
}

#endif
