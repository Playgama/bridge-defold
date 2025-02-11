#if defined(DM_PLATFORM_HTML5)
#include "bridge_player.h"
#include "bridge.h"

namespace {
    void cpp_bridge_player_authorize(dmScript::LuaCallbackInfo* success,
                                     dmScript::LuaCallbackInfo* failure, const int callbackType) {
        if (callbackType == 0 && dmScript::IsCallbackValid(success)) {
            lua_State* L = dmScript::GetCallbackLuaContext(success);
            if (dmScript::SetupCallback(success)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(success);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(failure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(failure);
            if (dmScript::SetupCallback(failure)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(failure);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (dmScript::IsCallbackValid(success)) {
            dmScript::DestroyCallback(success);
        }
        if (dmScript::IsCallbackValid(failure)) {
            dmScript::DestroyCallback(failure);
        }
    }
}

bool bridge::player::isAuthorizationSupported() {
    return js_bridge_player_isAuthorizationSupported();
}

bool bridge::player::isAuthorized() {
    return js_bridge_player_isAuthorized();
}

char* bridge::player::id() {
    return js_bridge_player_id();
}

char* bridge::player::name() {
    return js_bridge_player_name();
}

char* bridge::player::photos() {
    return js_bridge_player_photos();
}

void bridge::player::authorize(const char* oprions, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_player_authorize((AuthorizeHandler)cpp_bridge_player_authorize, oprions, onSuccess, onFailure);
}
#endif