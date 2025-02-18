let js_bridge_device = {
    js_bridge_device_type: function () {
        return CStrOrNull(bridge.device.type);
    }
}

mergeInto(LibraryManager.library, js_bridge_device);