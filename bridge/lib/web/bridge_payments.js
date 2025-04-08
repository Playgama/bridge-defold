let js_bridge_payments = {
    js_bridge_payments_isSupported: function () {
        return bridge.payments.isSupported;
    },

    js_bridge_payments_isAvailable: function () {
        return bridge.payments.isAvailable;
    },

    js_bridge_payments_isGetCatalogSupported: function () {
        return bridge.payments.isGetCatalogSupported;
    },

    js_bridge_payments_isGetPurchasesSupported: function () {
        return bridge.payments.isGetPurchasesSupported;
    },

    js_bridge_payments_isConsumePurchaseSupported: function () {
        return bridge.payments.isConsumePurchaseSupported;
    },

    js_bridge_payments_purchase: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.payments.purchase(jsOptions)
            .then(purchase => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(purchase));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_payments_consumePurchase: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.payments.consumePurchase(jsOptions)
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