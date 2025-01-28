#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*GameOnHandler)(dmScript::LuaCallbackInfo *callback, char *state);

extern "C" {
    void   js_bridge_game_on(GameOnHandler handler,
                            const char *eventName,
                            dmScript::LuaCallbackInfo *callback);
}

#endif