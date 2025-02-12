#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*ShareHandler)(dmScript::LuaCallbackInfo* onSuccess,
                             dmScript::LuaCallbackInfo* onFailure,
                             const int callbackType);

typedef void (*GetListHandler)(dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure,
                               const int callbackType, char* resultJson);

extern "C" {
    bool js_bridge_achievements_isSupported();

    bool js_bridge_achievements_isGetListSupported();

    bool js_bridge_achievements_isNativePopupSupported();

    void js_bridge_achievements_unlock(ShareHandler handler,
                                       const char* options,
                                       dmScript::LuaCallbackInfo* onSuccess,
                                       dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_achievements_getList(GetListHandler handler,
                                        const char* options,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_achievements_showNativePopup(ShareHandler handler,
                                                const char* options,
                                                dmScript::LuaCallbackInfo* onSuccess,
                                                dmScript::LuaCallbackInfo* onFailure);
}

#endif