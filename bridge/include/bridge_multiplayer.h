#pragma once

#if defined(DM_PLATFORM_HTML5)

#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    void js_bridge_multiplayer_on(OnHandler handler,
                                  const char* eventName,
                                  dmScript::LuaCallbackInfo* callback);

    bool js_bridge_multiplayer_isSupported();

    char* js_bridge_multiplayer_state();

    bool js_bridge_multiplayer_isInRoom();

    bool js_bridge_multiplayer_isHost();

    char* js_bridge_multiplayer_playerId();

    char* js_bridge_multiplayer_hostId();

    char* js_bridge_multiplayer_roomId();

    char* js_bridge_multiplayer_room();

    char* js_bridge_multiplayer_players();

    bool js_bridge_multiplayer_isInviteSupported();

    char* js_bridge_multiplayer_launchRoomId();

    char* js_bridge_multiplayer_syncState();

    void js_bridge_multiplayer_createRoom(UniversalHandler handler,
                                          const char* json,
                                          dmScript::LuaCallbackInfo* onSuccess,
                                          dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_multiplayer_joinRoom(UniversalHandler handler,
                                        const char* roomId,
                                        const char* json,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_multiplayer_joinOrCreateRoom(UniversalHandler handler,
                                                const char* json,
                                                dmScript::LuaCallbackInfo* onSuccess,
                                                dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_multiplayer_getRooms(UniversalHandler handler,
                                        const char* json,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_multiplayer_inviteToRoom(UniversalHandler handler,
                                            const char* json,
                                            dmScript::LuaCallbackInfo* onSuccess,
                                            dmScript::LuaCallbackInfo* onFailure);

    void js_bridge_multiplayer_leaveRoom();

    void js_bridge_multiplayer_setRoomOpen(bool isOpen);

    void js_bridge_multiplayer_setRoomVisible(bool isVisible);

    void js_bridge_multiplayer_setRoomProperties(const char* json);

    void js_bridge_multiplayer_setPlayerProperties(const char* json);

    void js_bridge_multiplayer_send(const char* json);

    void js_bridge_multiplayer_setSyncState(const char* json);
}

#endif
