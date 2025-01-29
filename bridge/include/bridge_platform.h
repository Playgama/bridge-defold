#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*SendMessageHandler)(dmScript::LuaCallbackInfo* success,
                                   dmScript::LuaCallbackInfo* failure,
                                   const int callbackType,
                                   char* errorString);

typedef void (*GetServerTimeHandler)(dmScript::LuaCallbackInfo* success,
                                     dmScript::LuaCallbackInfo* failure,
                                     const int callbackType,
                                     char* errorString,
                                     char* time);

extern "C" {
    char* js_bridge_platform_id();

    char* js_bridge_platform_language();

    char* js_bridge_platform_payload();

    char* js_bridge_platform_tld();

    void js_bridge_platform_sendMessage(SendMessageHandler handler,
                                        const char* eventName,
                                        dmScript::LuaCallbackInfo* success,
                                        dmScript::LuaCallbackInfo* failure);

    void js_bridge_platform_getServerTime(GetServerTimeHandler handler,
                                          dmScript::LuaCallbackInfo* success,
                                          dmScript::LuaCallbackInfo* failure);
}

#endif