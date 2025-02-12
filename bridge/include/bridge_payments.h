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
    bool js_bridge_payments_isSupported();

    bool js_bridge_payments_isGetCatalogSupported();

    bool js_bridge_payments_isGetPurchasesSupported();

    bool js_bridge_payments_isConsumePurchaseSupported();

    void js_bridge_payments_purchase(GetListHandler handler,
                                     const char* options,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_consumePurchase(ShareHandler handler,
                                            const char* options,
                                            dmScript::LuaCallbackInfo* onSuccess,
                                            dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_getCatalog(GetListHandler handler,
                                       dmScript::LuaCallbackInfo* onSuccess,
                                       dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_payments_getPurchases(GetListHandler handler,
                                         dmScript::LuaCallbackInfo* onSuccess,
                                         dmScript::LuaCallbackInfo* onFailure);
}

#endif