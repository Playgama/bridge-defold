#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    void js_bridge_achievements_unlock(UniversalHandler handler,
                                       const char* id,
                                       dmScript::LuaCallbackInfo* onSuccess,
                                       dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_achievements_getList(UniversalHandler handler,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
}

#endif