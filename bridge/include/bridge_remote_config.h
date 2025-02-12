#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*GetListHandler)(dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure,
                               const int callbackType, char* resultJson);

extern "C" {
    bool js_bridge_remoteConfig_isSupported();

    void js_bridge_remoteConfig_get(GetListHandler handler,
                                    const char* oprions,
                                    dmScript::LuaCallbackInfo* onSuccess,
                                    dmScript::LuaCallbackInfo* onFailure);
}

#endif