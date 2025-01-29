let js_bridge_platform = {
    js_bridge_platform_id: function () {
        return stringToNewUTF8(bridge.platform.id);
    },

    js_bridge_platform_language: function () {
        return stringToNewUTF8(bridge.platform.language);
    },

    js_bridge_platform_payload: function () {
        return stringToNewUTF8(bridge.platform.payload || ""); // TODO make null to nil on lua
    },

    js_bridge_platform_tld: function () {
        return stringToNewUTF8(bridge.platform.tld || ""); // TODO make null to nil on lua
    },

    js_bridge_platform_sendMessage: function (handler, message, success, failure) {
        bridge.platform.sendMessage(UTF8ToString(message))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, stringToNewUTF8(""));
            })
            .catch((error) => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, stringToNewUTF8("" + error));
            })
    },

    js_bridge_platform_getServerTime: function (handler, success, failure) {
        bridge.platform.getServerTime()
            .then(result => {
                {{{ makeDynCall('viiiii', 'handler') }}} (success, failure, 0, stringToNewUTF8(""), stringToNewUTF8(""+result));
            })
            .catch(error => {
                {{{ makeDynCall('viiiii', 'handler') }}} (success, failure, 1, stringToNewUTF8("" + error), stringToNewUTF8(""));
            })
    }
};

mergeInto(LibraryManager.library, js_bridge_platform);