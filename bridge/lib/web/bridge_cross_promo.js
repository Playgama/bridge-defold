let js_bridge_cross_promo = {
    js_bridge_cross_promo_getGamesList: function (handler, onSuccess, onFailure) {
        bridge.crossPromo.getGames()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_cross_promo_show: function () {
        bridge.crossPromo.show();
    },

    js_bridge_cross_promo_hide: function () {
        bridge.crossPromo.hide();
    },

    js_bridge_cross_promo_isVisible: function () {
        return bridge.crossPromo.isVisible;
    },
};

mergeInto(LibraryManager.library, js_bridge_cross_promo);
