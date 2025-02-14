#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    void js_bridge_game_on(OnHandler handler,
                           const char* eventName,
                           dmScript::LuaCallbackInfo* callback);

    char* js_bridge_game_visibilityState();
}

#endif