let js_bridge_storage = {
    js_bridge_storage_get: function (handler, jsonString, onSuccess, onFailure) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.get(values, true)
            .then(data => {
                const obj = {};
                for (let i = 0; i < values.length; i++) {
                    if(!data[i])
                        continue;
                    obj[values[i]] = data[i];
                }
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(obj));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    },

    js_bridge_storage_set: function (handler, jsonString, onSuccess, onFailure) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const keys = Object.keys(jsonObject);
        const values = Object.values(jsonObject);
        bridge.storage.set(keys, values)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    },

    js_bridge_storage_delete: function (handler, jsonString, onSuccess, onFailure) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.delete(values)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    }
}

mergeInto(LibraryManager.library, js_bridge_storage);
