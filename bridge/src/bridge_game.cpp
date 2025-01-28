#include <stdio.h>


#if defined(DM_PLATFORM_HTML5)
#include "bridge_game.h"
#include "bridge.h"

namespace { // private
    static void cpp_js_bridge_game_on(dmScript::LuaCallbackInfo *callback, char *state) {
        if (!dmScript::IsCallbackValid(callback)) {
            return;
        }

        lua_State *L = dmScript::GetCallbackLuaContext(callback);
        if (dmScript::SetupCallback(callback)) {
            lua_pushstring(L, state);
            dmScript::PCall(L, 2, 0);
            dmScript::TeardownCallback(callback);
        } else {
            dmLogError(" cpp_js_bridge_game_on Failed to setup callback");
        }
        free(state);
    }
}

void bridge::game::on(const char* eventName, dmScript::LuaCallbackInfo *callback) {
    js_bridge_game_on((GameOnHandler)cpp_js_bridge_game_on, eventName, callback);
}

#endif