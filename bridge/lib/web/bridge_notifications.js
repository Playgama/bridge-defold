let js_bridge_notifications = {
    js_bridge_notifications_isSupported: function () {
        return bridge.notifications.isSupported;
    },

    js_bridge_notifications_schedule: function (handler, options, onSuccess, onFailure) {
        var jsOptions = JSON.parse(UTF8ToString(options));
        bridge.notifications.schedule(jsOptions)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_notifications_cancel: function (handler, id, onSuccess, onFailure) {
        bridge.notifications.cancel(UTF8ToString(id))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },

    js_bridge_notifications_cancelAll: function (handler, onSuccess, onFailure) {
        bridge.notifications.cancelAll()
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
};

mergeInto(LibraryManager.library, js_bridge_notifications);
