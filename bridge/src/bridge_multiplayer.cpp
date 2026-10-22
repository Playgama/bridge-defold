#if defined(DM_PLATFORM_HTML5)
#include "bridge_multiplayer.h"
#include "bridge.h"

int bridge::multiplayer::on(lua_State* L) {
    return makeOnCallback(L, js_bridge_multiplayer_on);
}

int bridge::multiplayer::isSupported(lua_State* L) {
    return getBoolean(L, js_bridge_multiplayer_isSupported);
}

int bridge::multiplayer::state(lua_State* L) {
    return getString(L, js_bridge_multiplayer_state);
}

int bridge::multiplayer::isInRoom(lua_State* L) {
    return getBoolean(L, js_bridge_multiplayer_isInRoom);
}

int bridge::multiplayer::isHost(lua_State* L) {
    return getBoolean(L, js_bridge_multiplayer_isHost);
}

int bridge::multiplayer::playerId(lua_State* L) {
    return getString(L, js_bridge_multiplayer_playerId);
}

int bridge::multiplayer::hostId(lua_State* L) {
    return getString(L, js_bridge_multiplayer_hostId);
}

int bridge::multiplayer::roomId(lua_State* L) {
    return getString(L, js_bridge_multiplayer_roomId);
}

int bridge::multiplayer::room(lua_State* L) {
    return getJson(L, js_bridge_multiplayer_room);
}

int bridge::multiplayer::players(lua_State* L) {
    return getJson(L, js_bridge_multiplayer_players);
}

int bridge::multiplayer::isInviteSupported(lua_State* L) {
    return getBoolean(L, js_bridge_multiplayer_isInviteSupported);
}

int bridge::multiplayer::launchRoomId(lua_State* L) {
    return getString(L, js_bridge_multiplayer_launchRoomId);
}

int bridge::multiplayer::createRoom(lua_State* L) {
    return makeCallbackWithOptionalJson(L, js_bridge_multiplayer_createRoom, false);
}

int bridge::multiplayer::joinRoom(lua_State* L) {
    return makeCallbackWithStringAndOptionalJson(L, js_bridge_multiplayer_joinRoom, false);
}

int bridge::multiplayer::joinOrCreateRoom(lua_State* L) {
    return makeCallbackWithOptionalJson(L, js_bridge_multiplayer_joinOrCreateRoom, false);
}

int bridge::multiplayer::getRooms(lua_State* L) {
    return makeCallbackWithOptionalJson(L, js_bridge_multiplayer_getRooms, false);
}

int bridge::multiplayer::inviteToRoom(lua_State* L) {
    return makeCallbackWithOptionalJson(L, js_bridge_multiplayer_inviteToRoom, false);
}

int bridge::multiplayer::leaveRoom(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    js_bridge_multiplayer_leaveRoom();
    return 0;
}

int bridge::multiplayer::setRoomOpen(lua_State* L) {
    return callWithBoolean(L, js_bridge_multiplayer_setRoomOpen);
}

int bridge::multiplayer::setRoomVisible(lua_State* L) {
    return callWithBoolean(L, js_bridge_multiplayer_setRoomVisible);
}

int bridge::multiplayer::setRoomProperties(lua_State* L) {
    luaL_checktype(L, 1, LUA_TTABLE);
    return callWithJson(L, js_bridge_multiplayer_setRoomProperties);
}

int bridge::multiplayer::setPlayerProperties(lua_State* L) {
    luaL_checktype(L, 1, LUA_TTABLE);
    return callWithJson(L, js_bridge_multiplayer_setPlayerProperties);
}

int bridge::multiplayer::send(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checkstring(L, 1);

    // Pack type, data (any value) and options into one table at index 1 to encode it as a single JSON
    lua_newtable(L);
    lua_pushvalue(L, 1);
    lua_setfield(L, -2, "type");
    lua_pushvalue(L, 2);
    lua_setfield(L, -2, "data");
    if (lua_istable(L, 3)) {
        lua_pushvalue(L, 3);
        lua_setfield(L, -2, "options");
    }
    lua_replace(L, 1);

    char* json;
    size_t json_len;
    dmScript::LuaToJson(L, &json, &json_len);
    js_bridge_multiplayer_send(json);
    free(json);
    return 0;
}

#endif
