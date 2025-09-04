#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_player_isAuthorizationSupported();

    bool js_bridge_player_isAuthorized();

    char* js_bridge_player_id();

    char* js_bridge_player_name();

    char* js_bridge_player_extra();

    char* js_bridge_player_photos();

    void js_bridge_player_authorize(UniversalHandler handler,
                                    const char* json,
                                    dmScript::LuaCallbackInfo* onSuccess,
                                    dmScript::LuaCallbackInfo* onFailure);
}

#endif