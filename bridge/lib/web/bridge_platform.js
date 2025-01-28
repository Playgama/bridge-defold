let bridge_platform = {
    js_bridge_platform_id: function() {
        return stringToNewUTF8(window.bridge.platform.id);
    },

    js_bridge_platform_sdk: function() { // i dont know how
        return stringToNewUTF8(window.bridge.platform.id);
    },

    js_bridge_platform_language: function() {
        return stringToNewUTF8(window.bridge.platform.language);
    },
    
    js_bridge_platform_payload: function() {
        return stringToNewUTF8(window.bridge.platform.payload);
    },

    js_bridge_platform_tld: function() {
        return stringToNewUTF8(window.bridge.platform.tld);
    },

    js_bridge_platform_sendMessage: function(handler, message, success, failure) {
        window.bridge.platform.sendMessage(UTF8ToString(message))
                .then(() => {
                    {{{ makeDynCall('viiii', 'handler') }}}(success, failure, 0, stringToNewUTF8(""));
                })
                .catch((error) => {
                    {{{ makeDynCall('viiii', 'handler') }}}(success, failure, 1, stringToNewUTF8("" + error));
                })
    },

    js_bridge_platform_getServerTime: function(handler, success, failure) {
        window.bridge.platform.getServerTime()
                .then(result => {
                    {{{ makeDynCall('viiiii', 'handler') }}}(success, failure, 0, stringToNewUTF8(""), result);
                })
                .catch(error => {
                    {{{ makeDynCall('viiiii', 'handler') }}}(success, failure, 1, stringToNewUTF8("" + error), 0);
                })
    },

    js_bridge_game_on: function(handler, event_name, callback) { 
        console.log('js_bridge_game_on state:', UTF8ToString(event_name));
        window.bridge.game.on(UTF8ToString(event_name), state => {
            console.log('Visibility state:', state);
            {{{ makeDynCall('vii', 'handler') }}}(callback, stringToNewUTF8(state));
        });
    }


};


// autoAddDeps(LisGamesSDKLib, '$YGDefold');
mergeInto(LibraryManager.library, bridge_platform);