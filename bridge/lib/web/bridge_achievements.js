let js_bridge_achievements = {
    js_bridge_achievements_isSupported: function () {
        return bridge.achievements.isSupported;
    },

    js_bridge_achievements_isGetListSupported: function () {
        return bridge.achievements.isGetListSupported;
    },

    js_bridge_achievements_isNativePopupSupported: function () {
        return bridge.achievements.isNativePopupSupported;
    },

    js_bridge_achievements_unlock: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.achievements.unlock(jsOptions)
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_achievements_getList: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.achievements.getList(jsOptions)
            .then(result => {
                const jsonString = JSON.stringify(result);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_achievements_showNativePopup: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.achievements.showNativePopup(jsOptions)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson());
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_achievements);