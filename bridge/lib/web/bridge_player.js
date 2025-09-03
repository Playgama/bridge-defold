let js_bridge_player = {
    js_bridge_player_isAuthorizationSupported: function () {
        return bridge.player.isAuthorizationSupported;
    },

    js_bridge_player_isAuthorized: function () {
        return bridge.player.isAuthorized;
    },

    js_bridge_player_id: function () {
        return CStrOrNull(bridge.player.id);
    },

    js_bridge_player_name: function () {
        return CStrOrNull(bridge.player.name);
    },

    js_bridge_player_extra: function () {
        return CStrOrNull(bridge.player.extra);
    },

    js_bridge_player_photos: function () {
        return CStrOrNull(bridge.player.photos);
    },

    js_bridge_player_authorize: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.player.authorize(jsOptions)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_player);