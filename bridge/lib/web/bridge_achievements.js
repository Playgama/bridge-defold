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
            .then((result) => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 0, result);
            })
            .catch(error => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 1, false);
            })
    },

    js_bridge_achievements_getList: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.achievements.getList(jsOptions)
            .then((result) => {
                const jsonString = JSON.stringify(result);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull(error));
            })
    },

    js_bridge_achievements_showNativePopup: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.achievements.showNativePopup(jsOptions)
            .then(() => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 0);
            })
            .catch(error => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 1);
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_achievements);