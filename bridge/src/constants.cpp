
#include "constants.h"

namespace {
    void lua_pushtablestringstring(lua_State* L, const char* key, const char* value) {
        int top = lua_gettop(L);
        lua_pushstring(L, key);
        lua_pushstring(L, value);
        lua_settable(L, -3);
        assert(top == lua_gettop(L));
    }
}

void constants::registrateConstants(lua_State* L) {
    lua_pushstring(L, "PLATFORM_ID"); // create advertisement table
    lua_newtable(L);
    lua_pushtablestringstring(L, "VK", "vk");
    lua_pushtablestringstring(L, "OK", "ok");
    lua_pushtablestringstring(L, "YANDEX", "yandex");
    lua_pushtablestringstring(L, "CRAZY_GAMES", "crazy_games");
    lua_pushtablestringstring(L, "ABSOLUTE_GAMES", "GAME_DISTRIBUTION");
    lua_pushtablestringstring(L, "PLAYGAMA", "playgama");
    lua_pushtablestringstring(L, "WORTAL", "WORTAL");
    lua_pushtablestringstring(L, "PLAYDECK", "playdeck");
    lua_pushtablestringstring(L, "TELEGRAM", "telegram");
    lua_pushtablestringstring(L, "LAGGED", "lagged");
    lua_pushtablestringstring(L, "FACEBOOK", "facebook");
    lua_pushtablestringstring(L, "POKI", "poki");
    lua_pushtablestringstring(L, "MOCK", "mock");
    lua_pushtablestringstring(L, "QA_TOOL", "qa_tool");
    lua_settable(L, -3);
}
