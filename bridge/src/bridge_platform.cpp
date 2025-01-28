#include <stdio.h>


#if defined(DM_PLATFORM_HTML5)
#include "bridge_platform.h"
#include "bridge.h"

namespace { // private
    static void cpp_bridge_platform_sendMessage(dmScript::LuaCallbackInfo *success,
                                    dmScript::LuaCallbackInfo *failure,
                                    const int callbackType,
                                    char *errorString) 
    {
        char string[10];
        sprintf(string, "%d", callbackType);
        dmLogInfo(string);
        if (callbackType == 0 && dmScript::IsCallbackValid(success)) {
            lua_State *L = dmScript::GetCallbackLuaContext(success);
            if (dmScript::SetupCallback(success)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(success);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(failure)) {
            lua_State *L = dmScript::GetCallbackLuaContext(failure);
            if (dmScript::SetupCallback(failure)) {
                lua_pushstring(L, errorString);
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(failure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        // dmLogInfo("DestroyCallback");
        if (dmScript::IsCallbackValid(success)) {
            // dmLogInfo("DestroyCallback success");
            dmScript::DestroyCallback(success);
        }
        if (dmScript::IsCallbackValid(failure)) {
            // dmLogInfo("DestroyCallback failure");
            dmScript::DestroyCallback(failure);
        }
        free(errorString);
    }

    static void js_bridge_platform_getServerTime(dmScript::LuaCallbackInfo *success,
                                   dmScript::LuaCallbackInfo *failure,
                                   const int callbackType,
                                   char *errorString,
                                   long time)
    {
        if (callbackType == 0 && dmScript::IsCallbackValid(success)) {
            lua_State *L = dmScript::GetCallbackLuaContext(success);
            if (dmScript::SetupCallback(success)) {
                lua_pushinteger(L, time);
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(success);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(failure)) {
            lua_State *L = dmScript::GetCallbackLuaContext(failure);
            if (dmScript::SetupCallback(failure)) {
                lua_pushstring(L, errorString);
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(failure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        // dmLogInfo("DestroyCallback");
        if (dmScript::IsCallbackValid(success)) {
            // dmLogInfo("DestroyCallback success");
            dmScript::DestroyCallback(success);
        }
        if (dmScript::IsCallbackValid(failure)) {
            // dmLogInfo("DestroyCallback failure");
            dmScript::DestroyCallback(failure);
        }

        free(errorString);
    }
} // private

char* bridge::platform::id() {
    return js_bridge_platform_id();
}

char* bridge::platform::language() {
    return js_bridge_platform_language();
}

char* bridge::platform::tld() {
    return js_bridge_platform_tld();
}

char* bridge::platform::payload() {
    return js_bridge_platform_payload();
}

void bridge::platform::getServerTime(dmScript::LuaCallbackInfo *onSuccess, dmScript::LuaCallbackInfo *onFailure) {
    js_bridge_platform_getServerTime((GetServerTimeHandler)js_bridge_platform_getServerTime, onSuccess, onFailure);
}

void bridge::platform::sendMessage(const char* event, dmScript::LuaCallbackInfo *onSuccess, dmScript::LuaCallbackInfo *onFailure) {
    js_bridge_platform_sendMessage((SendMessageHandler)cpp_bridge_platform_sendMessage, event, onSuccess, onFailure);
}

#endif