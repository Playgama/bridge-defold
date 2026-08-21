#pragma once

#if defined(DM_PLATFORM_HTML5)

#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_notifications_isSupported();
    void js_bridge_notifications_schedule(UniversalHandler handler,
                                          const char* json,
                                          dmScript::LuaCallbackInfo* onSuccess,
                                          dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_notifications_cancel(UniversalHandler handler,
                                        const char* id,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_notifications_cancelAll(UniversalHandler handler,
                                           dmScript::LuaCallbackInfo* onSuccess,
                                           dmScript::LuaCallbackInfo* onFailure);
}

#endif
