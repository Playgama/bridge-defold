let js_bridge_platform = {
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

    js_bridge_platform_sendMessage: function (handler, message, success, failure) {
        bridge.platform.sendMessage(UTF8ToString(message))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, packToJson(error));
            })
    },

    js_bridge_platform_getServerTime: function (handler, success, failure) {
        bridge.platform.getServerTime()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, packToJson(error));
            })
    }
};

mergeInto(LibraryManager.library, js_bridge_platform);