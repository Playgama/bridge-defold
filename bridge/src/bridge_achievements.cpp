#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_achievements.h"

namespace { // private
    void cpp_ShareHandler(dmScript::LuaCallbackInfo* onSuccess,
                          dmScript::LuaCallbackInfo* onFailure,
                          const int callbackType) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                dmScript::PCall(L, 1, 0);
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
    }

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

bool bridge::achievements::isSupported() {
    return js_bridge_achievements_isSupported();
}

bool bridge::achievements::isGetListSupported() {
    return js_bridge_achievements_isGetListSupported();
}

bool bridge::achievements::isNativePopupSupported() {
    return js_bridge_achievements_isNativePopupSupported();
}

void bridge::achievements::unlock(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_achievements_unlock((ShareHandler)cpp_ShareHandler, options, onSuccess, onFailure);
}

void bridge::achievements::getList(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_achievements_getList((GetListHandler)cpp_GetListHandler, options, onSuccess, onFailure);
}

void bridge::achievements::showNativePopup(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_achievements_showNativePopup((ShareHandler)cpp_ShareHandler, options, onSuccess, onFailure);
}

#endif