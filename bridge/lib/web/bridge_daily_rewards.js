let js_bridge_daily_rewards = {
    js_bridge_daily_rewards_getRewards: function (handler, onSuccess, onFailure) {
        bridge.dailyRewards.getRewards()
            .then(result => {
                const jsonString = JSON.stringify(result);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_daily_rewards_getCurrentDay: function (handler, onSuccess, onFailure) {
        bridge.dailyRewards.getCurrentDay()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_daily_rewards_getCurrentReward: function (handler, onSuccess, onFailure) {
        bridge.dailyRewards.getCurrentReward()
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_daily_rewards_claimCurrentReward: function (handler, onSuccess, onFailure) {
        bridge.dailyRewards.claimCurrentReward()
            .then(claimed => {
                // claimed is a boolean: route to on_success when claimed, on_failure otherwise
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, claimed ? 0 : 1, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    }
}

mergeInto(LibraryManager.library, js_bridge_daily_rewards);
