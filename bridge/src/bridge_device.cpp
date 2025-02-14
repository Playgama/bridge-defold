#if defined(DM_PLATFORM_HTML5)
#include "bridge_device.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::device::type(lua_State* L) {
    return stringGetter(L, js_bridge_device_type);
}

#endif