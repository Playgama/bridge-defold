#if defined(DM_PLATFORM_HTML5)
#include "bridge_analytics.h"
#include "bridge.h"
#include "bridge_helper.h"

int bridge::analytics::send(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    size_t len;
    const char* eventName = luaL_checklstring(L, 1, &len);
    char* json = NULL;

    if (lua_istable(L, 2)) {
        size_t json_len;
        lua_pushvalue(L, 2);
        lua_replace(L, 1);
        dmScript::LuaToJson(L, &json, &json_len);
    }

    js_bridge_analytics_send(eventName, json);

    if (json) {
        free(json);
    }

    return 0;
}

#endif
