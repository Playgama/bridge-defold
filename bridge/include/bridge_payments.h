#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_payments_isSupported();

    void js_bridge_payments_purchase(UniversalHandler handler,
                                     const char* id,
                                     const char* json,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_consumePurchase(UniversalHandler handler,
                                            const char* id,
                                            dmScript::LuaCallbackInfo* onSuccess,
                                            dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_getCatalog(UniversalHandler handler,
                                       dmScript::LuaCallbackInfo* onSuccess,
                                       dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_getPurchases(UniversalHandler handler,
                                         dmScript::LuaCallbackInfo* onSuccess,
                                         dmScript::LuaCallbackInfo* onFailure);
}

#endif