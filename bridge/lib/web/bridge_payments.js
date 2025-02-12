let js_bridge_payments = {
    js_bridge_payments_isSupported: function () {
        return bridge.payments.isSupported;
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
            .then((purchase) => {
                const jsonString = JSON.stringify(purchase);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull(error));
            })
    },

    js_bridge_payments_consumePurchase: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.payments.consumePurchase(jsOptions)
            .then(() => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 0);
            })
            .catch(error => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 1);
            })
    },

    js_bridge_payments_getCatalog: function (handler, onSuccess, onFailure) {
        bridge.payments.getCatalog()
            .then((catalogItems) => {
                const jsonString = JSON.stringify(catalogItems);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull(error));
            })
    },

    js_bridge_payments_getPurchases: function (handler, onSuccess, onFailure) {
        bridge.payments.getPurchases()
            .then((purchases) => {
                const jsonString = JSON.stringify(purchases);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull(error));
            })
    },
    
}

mergeInto(LibraryManager.library, js_bridge_payments);