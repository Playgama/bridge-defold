let js_bridge_leaderboards = {
    js_bridge_leaderboards_type: function () {
        return bridge.leaderboards.type;
    },

    js_bridge_leaderboards_setScore: function (handler, id, score, onSuccess, onFailure) {
        bridge.leaderboards.setScore(UTF8ToString(id), parseInt(score))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                 {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_leaderboards_getEntries: function (handler, id, onSuccess, onFailure) {
        bridge.leaderboards.getEntries(UTF8ToString(id))
            .then(entries => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(entries));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
}

mergeInto(LibraryManager.library, js_bridge_leaderboards);