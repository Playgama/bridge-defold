let js_bridge_remoteConfig = {
    js_bridge_remoteConfig_isSupported: function () {
        return bridge.remoteConfig.isSupported;
    },

    js_bridge_remoteConfig_get: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.remoteConfig.get(jsOptions)
            .then(data => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(data));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
}

mergeInto(LibraryManager.library, js_bridge_remoteConfig);