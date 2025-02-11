let js_bridge_leaderboards = {
    js_bridge_leaderboard_isSupported: function () {
        return bridge.leaderboard.isSupported;
    },

    js_bridge_leaderboard_isNativePopupSupported: function () {
        return bridge.leaderboard.isNativePopupSupported;
    },

    js_bridge_leaderboard_isMultipleBoardsSupported: function () {
        return bridge.leaderboard.isMultipleBoardsSupported;
    },

    js_bridge_leaderboard_isSetScoreSupported: function () {
        return bridge.leaderboard.isSetScoreSupported;
    },

    js_bridge_leaderboard_isGetScoreSupported: function () {
        return bridge.leaderboard.isGetScoreSupported;
    },

    js_bridge_leaderboard_isGetEntriesSupported: function () {
        return bridge.leaderboard.isGetEntriesSupported;
    },

    js_bridge_leaderboard_setScore: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.setScore(jsOptions)
            .then(() => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 0);
            })
            .catch(error => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 1);
            })
    },

    js_bridge_leaderboard_getScore: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.getScore(jsOptions)
            .then(score => { // TODO maybe need fix from return value
                const jsonString = JSON.stringify(score);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull("" + error));
            })
    },

    js_bridge_leaderboard_getEntries: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.getEntries(jsOptions)
            .then(entries => {
                const jsonString = JSON.stringify(entries);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, CStrOrNull(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, CStrOrNull("" + error));
            })
    },

    js_bridge_leaderboard_showNativePopup: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.showNativePopup(jsOptions)
            .then(() => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 0);
            })
            .catch(error => {
                {{{ makeDynCall('viii', 'handler') }}} (onSuccess, onFailure, 1);
            })
    },
}

mergeInto(LibraryManager.library, js_bridge_leaderboards);