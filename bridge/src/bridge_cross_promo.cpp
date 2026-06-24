#if defined(DM_PLATFORM_HTML5)
#include "bridge_cross_promo.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::crossPromo::getGamesList(lua_State* L) {
    return makeCallback(L, js_bridge_cross_promo_getGamesList, false);
}

int bridge::crossPromo::show(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    js_bridge_cross_promo_show();
    return 0;
}

int bridge::crossPromo::hide(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    js_bridge_cross_promo_hide();
    return 0;
}

int bridge::crossPromo::isVisible(lua_State* L) {
    return getBoolean(L, js_bridge_cross_promo_isVisible);
}

#endif
