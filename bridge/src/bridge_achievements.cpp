#if defined(DM_PLATFORM_HTML5)
#include "bridge_achievements.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::achievements::isSupported(lua_State* L) {
    return boolGetter(L, js_bridge_achievements_isSupported);
}

int bridge::achievements::isGetListSupported(lua_State* L) {
    return boolGetter(L, js_bridge_achievements_isGetListSupported);
}

int bridge::achievements::isNativePopupSupported(lua_State* L) {
    return boolGetter(L, js_bridge_achievements_isNativePopupSupported);
}

int bridge::achievements::unlock(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_achievements_unlock, true);
}

int bridge::achievements::getList(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_achievements_getList, true);
}

int bridge::achievements::showNativePopup(lua_State* L) {
    return voidJsonCallbacksGetter(L, js_bridge_achievements_showNativePopup, true);
}

#endif