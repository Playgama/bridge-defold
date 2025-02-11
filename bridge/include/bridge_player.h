#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*AuthorizeHandler)(dmScript::LuaCallbackInfo* success,
                                 dmScript::LuaCallbackInfo* failure,
                                int callbackType);

extern "C" {
    bool js_bridge_player_isAuthorizationSupported();

    bool js_bridge_player_isAuthorized();

    char* js_bridge_player_id();

    char* js_bridge_player_name();

    char* js_bridge_player_photos();

    void js_bridge_player_authorize(AuthorizeHandler handler,
                                     const char* oprions,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);
}

#endif