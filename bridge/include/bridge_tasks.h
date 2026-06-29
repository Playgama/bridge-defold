#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    void js_bridge_tasks_getTasks(UniversalHandler handler,
                                  dmScript::LuaCallbackInfo* onSuccess,
                                  dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_tasks_addProgress(UniversalHandler handler,
                                     const char* metric,
                                     int amount,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_tasks_claimReward(UniversalHandler handler,
                                     const char* taskId,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);
}

#endif
