let js_bridge_remoteConfig = {
    js_bridge_remoteConfig_isSupported: function () {
        return bridge.remoteConfig.isSupported;
    },

    js_bridge_remoteConfig_setDynamicParameters: function (parameters) {
        var jsParameters = JSON.parse(UTF8ToString(parameters));
        bridge.remoteConfig.setDynamicParameters(jsParameters);
    },

    js_bridge_remoteConfig_get: function (handler, onSuccess, onFailure) {
        bridge.remoteConfig.get()
            .then(data => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(data));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
}

mergeInto(LibraryManager.library, js_bridge_remoteConfig);