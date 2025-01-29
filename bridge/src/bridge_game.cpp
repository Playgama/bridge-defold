#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_game.h"

namespace { // private
    void cpp_bridge_game_on(dmScript::LuaCallbackInfo* callback, char* state) {
        if (!dmScript::IsCallbackValid(callback)) {
            return;
        }

        lua_State* L = dmScript::GetCallbackLuaContext(callback);
        if (dmScript::SetupCallback(callback)) {
            lua_pushstring(L, state);
            dmScript::PCall(L, 2, 0);
            dmScript::TeardownCallback(callback);
        } else {
            dmLogError("cpp_bridge_game_on Failed to setup callback");
        }
        free(state);
    }
} // namespace

void bridge::game::on(const char* eventName, dmScript::LuaCallbackInfo* callback) {
    js_bridge_game_on((GameOnHandler)cpp_bridge_game_on, eventName, callback);
}

char* bridge::game::visibilityState() { return js_bridge_game_visibilityState(); }

#endif