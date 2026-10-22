let js_bridge_multiplayer = {
    js_bridge_multiplayer_on: function (handler, event_name, callback) {
        bridge.multiplayer.on(UTF8ToString(event_name), payload => {
            {{{ makeDynCall('vii', 'handler') }}} (callback, packToJson(payload));
        });
    },

    js_bridge_multiplayer_isSupported: function () {
        return bridge.multiplayer.isSupported;
    },

    js_bridge_multiplayer_state: function () {
        return CStrOrNull(bridge.multiplayer.state);
    },

    js_bridge_multiplayer_isInRoom: function () {
        return bridge.multiplayer.isInRoom;
    },

    js_bridge_multiplayer_isHost: function () {
        return bridge.multiplayer.isHost;
    },

    js_bridge_multiplayer_playerId: function () {
        return CStrOrNull(bridge.multiplayer.playerId);
    },

    js_bridge_multiplayer_hostId: function () {
        return CStrOrNull(bridge.multiplayer.hostId);
    },

    js_bridge_multiplayer_roomId: function () {
        return CStrOrNull(bridge.multiplayer.roomId);
    },

    js_bridge_multiplayer_room: function () {
        return packToJson(bridge.multiplayer.room);
    },

    js_bridge_multiplayer_players: function () {
        return packToJson(bridge.multiplayer.players);
    },

    js_bridge_multiplayer_isInviteSupported: function () {
        return bridge.multiplayer.isInviteSupported;
    },

    js_bridge_multiplayer_launchRoomId: function () {
        return CStrOrNull(bridge.multiplayer.launchRoomId);
    },

    js_bridge_multiplayer_createRoom: function (handler, options, onSuccess, onFailure) {
        var jsOptions = options ? JSON.parse(UTF8ToString(options)) : undefined;
        bridge.multiplayer.createRoom(jsOptions)
            .then(roomId => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(roomId));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error && error.code));
            })
    },

    js_bridge_multiplayer_joinRoom: function (handler, roomId, options, onSuccess, onFailure) {
        var jsRoomId = UTF8ToString(roomId);
        var jsOptions = options ? JSON.parse(UTF8ToString(options)) : undefined;
        bridge.multiplayer.joinRoom(jsRoomId, jsOptions)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error && error.code));
            })
    },

    js_bridge_multiplayer_joinOrCreateRoom: function (handler, options, onSuccess, onFailure) {
        var jsOptions = options ? JSON.parse(UTF8ToString(options)) : undefined;
        bridge.multiplayer.joinOrCreateRoom(jsOptions)
            .then(roomId => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(roomId));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error && error.code));
            })
    },

    js_bridge_multiplayer_getRooms: function (handler, options, onSuccess, onFailure) {
        var jsOptions = options ? JSON.parse(UTF8ToString(options)) : undefined;
        bridge.multiplayer.getRooms(jsOptions)
            .then(rooms => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(rooms));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error && error.code));
            })
    },

    js_bridge_multiplayer_inviteToRoom: function (handler, options, onSuccess, onFailure) {
        var jsOptions = options ? JSON.parse(UTF8ToString(options)) : undefined;
        bridge.multiplayer.inviteToRoom(jsOptions)
            .then(result => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(result));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error && error.code));
            })
    },

    js_bridge_multiplayer_leaveRoom: function () {
        bridge.multiplayer.leaveRoom();
    },

    js_bridge_multiplayer_setRoomOpen: function (isOpen) {
        bridge.multiplayer.setRoomOpen(!!isOpen);
    },

    js_bridge_multiplayer_setRoomVisible: function (isVisible) {
        bridge.multiplayer.setRoomVisible(!!isVisible);
    },

    js_bridge_multiplayer_setRoomProperties: function (properties) {
        bridge.multiplayer.setRoomProperties(JSON.parse(UTF8ToString(properties)));
    },

    js_bridge_multiplayer_setPlayerProperties: function (properties) {
        bridge.multiplayer.setPlayerProperties(JSON.parse(UTF8ToString(properties)));
    },

    js_bridge_multiplayer_send: function (message) {
        // The message is packed by the C++ side as { type, data, options }
        var jsMessage = JSON.parse(UTF8ToString(message));
        bridge.multiplayer.send(jsMessage.type, jsMessage.data, jsMessage.options);
    },
};

mergeInto(LibraryManager.library, js_bridge_multiplayer);
