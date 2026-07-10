let js_bridge_tasks = {
    js_bridge_tasks_getTasks: function (handler, onSuccess, onFailure) {
        bridge.tasks.getTasks()
            .then(result => {
                const jsonString = JSON.stringify(result);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_tasks_addProgress: function (handler, metric, amount, onSuccess, onFailure) {
        bridge.tasks.addProgress(UTF8ToString(metric), parseInt(amount))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_tasks_claimReward: function (handler, taskId, onSuccess, onFailure) {
        bridge.tasks.claimReward(UTF8ToString(taskId))
            .then(claimed => {
                // claimed is a boolean: route to on_success when claimed, on_failure otherwise
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, claimed ? 0 : 1, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_tasks);
