#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_achievements_isSupported();

    bool js_bridge_achievements_isGetListSupported();

    bool js_bridge_achievements_isNativePopupSupported();

    void js_bridge_achievements_unlock(UniversalHandler handler,
                                       const char* options,
                                       dmScript::LuaCallbackInfo* onSuccess,
                                       dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_achievements_getList(UniversalHandler handler,
                                        const char* options,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_achievements_showNativePopup(UniversalHandler handler,
                                                const char* options,
                                                dmScript::LuaCallbackInfo* onSuccess,
                                                dmScript::LuaCallbackInfo* onFailure);
}

#endif