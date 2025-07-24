#pragma once

#include <dmsdk/sdk.h>
#include "bridge_helper.h"

#if defined(DM_PLATFORM_HTML5)

extern "C" {
    void js_bridge_platform_on(OnHandler handler,
        const char* eventName,
        dmScript::LuaCallbackInfo* callback);
    
    char* js_bridge_platform_id();

    char* js_bridge_platform_language();

    char* js_bridge_platform_payload();

    char* js_bridge_platform_tld();

    void js_bridge_platform_sendMessage(UniversalHandler handler,
                                        const char* eventName,
                                        dmScript::LuaCallbackInfo* success,
                                        dmScript::LuaCallbackInfo* failure);

    void js_bridge_platform_getServerTime(UniversalHandler handler,
                                        dmScript::LuaCallbackInfo* success,
                                        dmScript::LuaCallbackInfo* failure);

    bool js_bridge_platform_isAudioEnabled();
    
    bool js_bridge_platform_isGetAllGamesSupported();

    void js_bridge_platform_getAllGames(UniversalHandler handler,
                                        dmScript::LuaCallbackInfo* success,
                                        dmScript::LuaCallbackInfo* failure);

    bool js_bridge_platform_isGetGameByIdSupported();

    void js_bridge_platform_getGameById(UniversalHandler handler,
                                        const char* json,
                                        dmScript::LuaCallbackInfo* success,
                                        dmScript::LuaCallbackInfo* failure);
}

#endif