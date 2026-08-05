#if defined(DM_PLATFORM_HTML5)
#include "bridge_notifications.h"
#include "bridge.h"

int bridge::notifications::isSupported(lua_State* L) {
    return getBoolean(L, js_bridge_notifications_isSupported);
}

int bridge::notifications::schedule(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_notifications_schedule, false);
}

int bridge::notifications::cancel(lua_State* L) {
    return makeCallbackWithString(L, js_bridge_notifications_cancel, false);
}

int bridge::notifications::cancelAll(lua_State* L) {
    return makeCallback(L, js_bridge_notifications_cancelAll, false);
}

#endif
