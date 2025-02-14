#if defined(DM_PLATFORM_HTML5)
#include "bridge_game.h"
#include "bridge.h"

int bridge::game::on(lua_State* L) {
    return makeOnCallback(L, js_bridge_game_on);
}

int bridge::game::visibilityState(lua_State* L) {
    return getString(L, js_bridge_game_visibilityState);
}

#endif