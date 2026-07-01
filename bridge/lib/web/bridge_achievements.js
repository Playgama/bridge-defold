let js_bridge_achievements = {
    js_bridge_achievements_unlock: function (handler, id, onSuccess, onFailure) {
        bridge.achievements.unlock(UTF8ToString(id))
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_achievements_getAchievements: function (handler, onSuccess, onFailure) {
        bridge.achievements.getAchievements()
            .then(result => {
                const jsonString = JSON.stringify(result);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_achievements);