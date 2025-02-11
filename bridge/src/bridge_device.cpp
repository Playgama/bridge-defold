#if defined(DM_PLATFORM_HTML5)
#include "bridge_device.h"
#include "bridge.h"

char* bridge::device::type() {
    return js_bridge_device_type();
}

#endif