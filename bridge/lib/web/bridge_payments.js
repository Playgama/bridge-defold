let js_bridge_payments = {
    js_bridge_payments_isSupported: function () {
        return bridge.payments.isSupported;
    },

    js_bridge_payments_purchase: function (handler, id, onSuccess, onFailure) {
        bridge.payments.purchase(UTF8ToString(id))
            .then(purchase => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(purchase));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_payments_consumePurchase: function (handler, id, onSuccess, onFailure) {
        bridge.payments.consumePurchase(UTF8ToString(id))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_payments_getCatalog: function (handler, onSuccess, onFailure) {
        bridge.payments.getCatalog()
            .then(catalogItems => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(catalogItems));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_payments_getPurchases: function (handler, onSuccess, onFailure) {
        bridge.payments.getPurchases()
            .then(purchases => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(purchases));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    
}

mergeInto(LibraryManager.library, js_bridge_payments);