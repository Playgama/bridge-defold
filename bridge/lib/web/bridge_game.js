let js_bridge_game = {
    js_bridge_game_on: function (handler, event_name, callback) {
        bridge.game.on(UTF8ToString(event_name), state => {
            {{{ makeDynCall('vii', 'handler') }}} (callback, stringToNewUTF8(state));
        });
    },

    js_bridge_game_visibilityState: function () {
        return bridge.game.visibilityState;
    }
}

mergeInto(LibraryManager.library, js_bridge_game);