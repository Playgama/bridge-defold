let js_bridge_storage = {
    js_bridge_storage_defaultType() {
        return CStrOrNull(bridge.storage.defaultType);
    },

    js_bridge_storage_isAvailable(storageType) {
        return bridge.storage.isAvailable(UTF8ToString(storageType));
    },
    
    js_bridge_storage_isSupported(storageType) {
        return bridge.storage.isSupported(UTF8ToString(storageType));
    },

    js_bridge_storage_get: function (handler, jsonString, onSuccess, onFailure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.get(values, UTF8ToString(storageType), true)
            .then(data => {
                const obj = {};
                for (let i = 0; i < values.length; i++) {
                    if(!data[i])
                        continue;
                    obj[values[i]] = data[i];
                }
                console.log(data);
                const jsonString = JSON.stringify(obj);
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    },

    js_bridge_storage_set: function (handler, jsonString, onSuccess, onFailure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const keys = Object.keys(jsonObject);
        const values = Object.values(jsonObject);
        bridge.storage.set(keys, values, UTF8ToString(storageType))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    },

    js_bridge_storage_delete: function (handler, jsonString, onSuccess, onFailure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.delete(values, UTF8ToString(storageType))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            });
    }
}

mergeInto(LibraryManager.library, js_bridge_storage);