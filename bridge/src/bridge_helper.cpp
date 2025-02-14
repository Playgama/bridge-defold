#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <string>

namespace {
    void destroyCallbacks(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
        if (dmScript::IsCallbackValid(onSuccess)) {
            dmScript::DestroyCallback(onSuccess);
        }
        if (dmScript::IsCallbackValid(onFailure)) {
            dmScript::DestroyCallback(onFailure);
        }
    }

    void callCallback(dmScript::LuaCallbackInfo* callback, const char* data) {
        if (!dmScript::IsCallbackValid(callback))
            return;

        if (!dmScript::SetupCallback(callback)) {
            dmLogError("Failed to setup onSuccess");
            return;
        }

        lua_State* L = dmScript::GetCallbackLuaContext(callback);
        if (data) {
            dmScript::JsonToLua(L, data, strlen(data));
            lua_pushstring(L, "data");
            lua_gettable(L, -2); // get data from table
            lua_replace(L, -2); // replace table to data
        } else {
            lua_pushnil(L); // if data == null push nil like default value
        }
        dmScript::PCall(L, 2, 0);
        dmScript::TeardownCallback(callback);
    }
}

void cppUniversalHandler(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure, int callbackType, char* data) {
    if (callbackType == 0) {
        callCallback(onSuccess, data);
    }

    if (callbackType == 1) {
        callCallback(onFailure, data);
    }

    destroyCallbacks(onSuccess, onFailure);
    free(data);
}

void cppRuntimeHandler(dmScript::LuaCallbackInfo* onSuccess, char* data) {
    callCallback(onSuccess, data);
    free(data);
}

int stringGetter(lua_State* L, stringFunction func) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = func();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

int boolGetter(lua_State* L, boolFunction func) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isAvailable = func();
    lua_pushboolean(L, isAvailable);
    return 1;
}

int voidCallbacksGetter(lua_State* L, voidCallbacksFunction func, bool isRequiredFirstCallback) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    if (isRequiredFirstCallback) {
        onSuccess = dmScript::CreateCallback(L, 1);
    } else if (lua_isfunction(L, 1)) {
        onSuccess = dmScript::CreateCallback(L, 1);
    }

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    func((UniversalHandler)cppUniversalHandler, onSuccess, onFailure);
    return 0;
}

int voidStringCallbacksGetter(lua_State* L, voidStringCallbacksFunction func, bool isRequiredFirstCallback) {
    DM_LUA_STACK_CHECK(L, 0);
    size_t len;
    const char* event = luaL_checklstring(L, 1, &len);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (isRequiredFirstCallback) {
        onSuccess = dmScript::CreateCallback(L, 2);
    } else if (lua_isfunction(L, 2)) {
        onSuccess = dmScript::CreateCallback(L, 2);
    }

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    func((UniversalHandler)cppUniversalHandler, event, onSuccess, onFailure);
    return 0;
}

int runtimeOnGetter(lua_State* L, runtimeOnFunction func) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);
    func(cppRuntimeHandler, event_name, callback);
    return 0;
}

int voidJsonCallbacksGetter(lua_State* L, voidStringCallbacksFunction func, bool isRequiredFirstCallback) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    if (isRequiredFirstCallback) {
        onSuccess = dmScript::CreateCallback(L, 2);
    } else if (lua_isfunction(L, 2)) {
        onSuccess = dmScript::CreateCallback(L, 2);
    }

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    func((UniversalHandler)cppUniversalHandler, json, onSuccess, onFailure);
    free(json);
    return 0;
}

int boolStringGetter(lua_State* L, boolStringFunction func) {
    DM_LUA_STACK_CHECK(L, 1);
    const char* lstring = luaL_checkstring(L, 1);
    bool isAvailable = func(lstring);
    lua_pushboolean(L, isAvailable);
    return 1;
}

int storageFunctionGetter(lua_State* L, storageFunction func, bool isRequiredFirstCallback) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (isRequiredFirstCallback) {
        onSuccess = dmScript::CreateCallback(L, 2);
    } else if (lua_isfunction(L, 2)) {
        onSuccess = dmScript::CreateCallback(L, 2);
    }

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    func((UniversalHandler)cppUniversalHandler, json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}

#endif