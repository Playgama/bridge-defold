#if defined(DM_PLATFORM_HTML5)
#include "bridge_player.h"
#include "bridge.h"

int bridge::player::isAuthorizationSupported(lua_State* L) {
    return boolGetter(L, js_bridge_player_isAuthorizationSupported);
}

int bridge::player::isAuthorized(lua_State* L) {
    return boolGetter(L, js_bridge_player_isAuthorized);
}

int bridge::player::id(lua_State* L) {
    return stringGetter(L, js_bridge_player_id);
}

int bridge::player::name(lua_State* L) {
    return stringGetter(L, js_bridge_player_name);
}

int bridge::player::photos(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* photosJson = js_bridge_player_photos();
    dmScript::JsonToLua(L, photosJson, strlen(photosJson));
    free(photosJson);
    return 1;
}

int bridge::player::authorize(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_player_authorize, false);
}
#endif