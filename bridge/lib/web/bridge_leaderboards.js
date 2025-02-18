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
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                 {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_leaderboard_getScore: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.getScore(jsOptions)
            .then(score => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(score));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_leaderboard_getEntries: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.getEntries(jsOptions)
            .then(entries => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(entries));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_leaderboard_showNativePopup: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.social.showNativePopup(jsOptions)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
}

mergeInto(LibraryManager.library, js_bridge_leaderboards);