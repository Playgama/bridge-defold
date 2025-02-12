#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_payments.h"

namespace { // private
    void cpp_ShareHandler(dmScript::LuaCallbackInfo* onSuccess,
                          dmScript::LuaCallbackInfo* onFailure,
                          const int callbackType) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onFailure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (dmScript::IsCallbackValid(onSuccess)) {
            dmScript::DestroyCallback(onSuccess);
        }
        if (dmScript::IsCallbackValid(onFailure)) {
            dmScript::DestroyCallback(onFailure);
        }
    }

    void cpp_GetListHandler(dmScript::LuaCallbackInfo* onSuccess,
                            dmScript::LuaCallbackInfo* onFailure,
                            const int callbackType, char* resultJson) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::JsonToLua(L, resultJson, strlen(resultJson));
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onSuccess");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                lua_pushstring(L, resultJson);
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(onFailure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (dmScript::IsCallbackValid(onSuccess)) {
            dmScript::DestroyCallback(onSuccess);
        }
        if (dmScript::IsCallbackValid(onFailure)) {
            dmScript::DestroyCallback(onFailure);
        }
        free(resultJson);
    }
} // namespace


bool bridge::payments::isSupported() {
    return js_bridge_payments_isSupported();
}
bool bridge::payments::isGetCatalogSupported() {
    return js_bridge_payments_isGetCatalogSupported();
}
bool bridge::payments::isGetPurchasesSupported() {
    return js_bridge_payments_isGetPurchasesSupported();
}
bool bridge::payments::isConsumePurchaseSupported() {
    return js_bridge_payments_isConsumePurchaseSupported();
}

void bridge::payments::purchase(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_payments_purchase((GetListHandler)cpp_GetListHandler, options, onSuccess, onFailure);
}

void bridge::payments::consumePurchase(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_payments_consumePurchase((ShareHandler)cpp_ShareHandler, options, onSuccess, onFailure);
}

void bridge::payments::getCatalog(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_payments_getCatalog((GetListHandler)cpp_GetListHandler, onSuccess, onFailure);
}

void bridge::payments::getPurchases(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_payments_getPurchases((GetListHandler)cpp_GetListHandler, onSuccess, onFailure);
}

#endif