let js_bridge_platform = {
    js_bridge_platform_on: function (handler, event_name, callback) {
        bridge.platform.on(UTF8ToString(event_name), state => {
            {{{ makeDynCall('vii', 'handler') }}} (callback, packToJson(state));
        });
    },

    js_bridge_platform_id: function () {
        return CStrOrNull(bridge.platform.id);
    },

    js_bridge_platform_language: function () {
        return CStrOrNull(bridge.platform.language);
    },

    js_bridge_platform_payload: function () {
        return CStrOrNull(bridge.platform.payload);
    },

    js_bridge_platform_tld: function () {
        return CStrOrNull(bridge.platform.tld);
    },

    js_bridge_platform_sendMessage: function (handler, message, onSuccess, onFailure) {
        bridge.platform.sendMessage(UTF8ToString(message))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_platform_getServerTime: function (handler, onSuccess, onFailure) {
        bridge.platform.getServerTime()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_platform_isAudioEnabled: function () {
        return bridge.platform.isAudioEnabled;
    },

    js_bridge_platform_isGetAllGamesSupported: function () {
        return bridge.platform.isGetAllGamesSupported;
    },

    js_bridge_platform_isGetGameByIdSupported: function () {
        return bridge.platform.isGetGameByIdSupported;
    },

    js_bridge_platform_getAllGames: function (handler, onSuccess, onFailure) {
        bridge.platform.getAllGames()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_platform_getGameById: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.platform.getGameById(jsOptions)
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
};

mergeInto(LibraryManager.library, js_bridge_platform);