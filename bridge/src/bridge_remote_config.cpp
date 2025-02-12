#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_remote_config.h"

namespace { // private
    void cpp_GetListHandler(dmScript::LuaCallbackInfo* onSuccess,
                            dmScript::LuaCallbackInfo* onFailure,
                            const int callbackType, char* resultJson) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::JsonToLua(L, resultJson, strlen(resultJson));
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onSuccess");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                lua_pushstring(L, resultJson);
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(onFailure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (dmScript::IsCallbackValid(onSuccess)) {
            dmScript::DestroyCallback(onSuccess);
        }
        if (dmScript::IsCallbackValid(onFailure)) {
            dmScript::DestroyCallback(onFailure);
        }
        free(resultJson);
    }
} // namespace

bool bridge::remoteConfig::isSupported() {
    return js_bridge_remoteConfig_isSupported();
}

void bridge::remoteConfig::get(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_remoteConfig_get((GetListHandler)cpp_GetListHandler, options, onSuccess, onFailure);
}

#endif