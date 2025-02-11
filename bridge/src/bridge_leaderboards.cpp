#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_leaderboards.h"

namespace { // private
    void cpp_get_data_handler(dmScript::LuaCallbackInfo* onSuccess,
                              dmScript::LuaCallbackInfo* onFailure,
                              const int callbackType, char* dataOrError) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::JsonToLua(L, dataOrError, strlen(dataOrError));
                dmScript::PCall(L, 2, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onSuccess");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                lua_pushstring(L, dataOrError);
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
        free(dataOrError);
    }
    void cpp_set_data_handler(dmScript::LuaCallbackInfo* onSuccess,
                              dmScript::LuaCallbackInfo* onFailure, int callbackType) {
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
} // namespace

bool bridge::leaderboards::isSupported() {
    return js_bridge_leaderboard_isSupported();
}

bool bridge::leaderboards::isNativePopupSupported() {
    return js_bridge_leaderboard_isNativePopupSupported();
}

bool bridge::leaderboards::isMultipleBoardsSupported() {
    return js_bridge_leaderboard_isMultipleBoardsSupported();
}
bool bridge::leaderboards::isSetScoreSupported() {
    return js_bridge_leaderboard_isSetScoreSupported();
}
bool bridge::leaderboards::isGetScoreSupported() {
    return js_bridge_leaderboard_isGetScoreSupported();
}
bool bridge::leaderboards::isGetEntriesSupported() {
    return js_bridge_leaderboard_isGetEntriesSupported();
}

void bridge::leaderboards::setScore(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_leaderboard_setScore((SetDataHandler)cpp_set_data_handler, options, onSuccess, onFailure);
}

void bridge::leaderboards::getScore(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_leaderboard_getScore((GetDataHandler)cpp_get_data_handler, options, onSuccess, onFailure);
}

void bridge::leaderboards::getEntries(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_leaderboard_getEntries((GetDataHandler)cpp_get_data_handler, options, onSuccess, onFailure);
}

void bridge::leaderboards::showNativePopup(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_leaderboard_showNativePopup((SetDataHandler)cpp_set_data_handler, options, onSuccess, onFailure);
}

#endif