#pragma once

#if defined(DM_PLATFORM_HTML5)

extern "C" {
    void js_bridge_analytics_send(const char* eventName, const char* json);
}

#endif
