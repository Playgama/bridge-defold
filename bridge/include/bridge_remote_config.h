#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_remoteConfig_isSupported();

    void js_bridge_remoteConfig_get(UniversalHandler handler,
                                    const char* json,
                                    dmScript::LuaCallbackInfo* onSuccess,
                                    dmScript::LuaCallbackInfo* onFailure);
}

#endif