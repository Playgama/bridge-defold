#if defined(DM_PLATFORM_HTML5)
#include "bridge_payments.h"
#include "bridge.h"

int bridge::payments::isSupported(lua_State* L) {
    return getBoolean(L, js_bridge_payments_isSupported);
}

int bridge::payments::purchase(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_payments_purchase, true);
}

int bridge::payments::consumePurchase(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_payments_consumePurchase, true);
}

int bridge::payments::getCatalog(lua_State* L) {
    return makeCallback(L, js_bridge_payments_getCatalog, true);
}

int bridge::payments::getPurchases(lua_State* L) {
    return makeCallback(L, js_bridge_payments_getPurchases, true);
}

#endif