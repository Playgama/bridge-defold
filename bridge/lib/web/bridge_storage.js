let js_bridge_storage = {
    js_bridge_storage_defaultType() {
        return stringToNewUTF8(bridge.storage.defaultType);
    },

    js_bridge_storage_isAvailable(storageType) {
        return bridge.storage.isAvailable(UTF8ToString(storageType));
    },
    
    js_bridge_storage_isSupported(storageType) {
        return bridge.storage.isSupported(UTF8ToString(storageType));
    },

    js_bridge_storage_get: function (handler, jsonString, success, failure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.get(values, UTF8ToString(storageType), true)
            .then(data => {
                const obj = {};
                for (let i = 0; i < values.length; i++) {
                    obj[values[i]] = data[i];
                }

                const jsonString = JSON.stringify(obj);
                console.log(jsonString);
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, stringToNewUTF8(jsonString));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, stringToNewUTF8("" + error));
            });
    },

    js_bridge_storage_set: function (handler, jsonString, success, failure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const keys = Object.keys(jsonObject);
        const values = Object.values(jsonObject);
        bridge.storage.set(keys, values, UTF8ToString(storageType))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, stringToNewUTF8(""));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, stringToNewUTF8("" + error));
            });
    },

    js_bridge_storage_delete: function (handler, jsonString, success, failure, storageType) {
        const jsonObject = JSON.parse(UTF8ToString(jsonString));
        const values = Object.values(jsonObject);
        bridge.storage.delete(values, UTF8ToString(storageType))
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 0, stringToNewUTF8(""));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (success, failure, 1, stringToNewUTF8("" + error));
            });
    }
}

mergeInto(LibraryManager.library, js_bridge_storage);