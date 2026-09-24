let js_bridge_analytics = {
    js_bridge_analytics_send: function (eventName, data) {
        var jsEventName = UTF8ToString(eventName);
        var jsData = data ? JSON.parse(UTF8ToString(data)) : undefined;
        bridge.analytics.send(jsEventName, jsData);
    }
}

mergeInto(LibraryManager.library, js_bridge_analytics);
