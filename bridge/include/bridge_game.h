#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*GameOnHandler)(dmScript::LuaCallbackInfo *success,
                                    dmScript::LuaCallbackInfo *failure,
                                    const int callbackType,
                                    char *errorString,
                                    long time);

extern "C" {
    void   js_bridge_game_on(GameOnHandler handler,
                                        const char *eventName,
                                        dmScript::LuaCallbackInfo *callback);
}

#endif