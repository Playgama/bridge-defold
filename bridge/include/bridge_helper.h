#pragma once

#if defined(DM_PLATFORM_HTML5)
#include <dmsdk/sdk.h>

typedef void (*UniversalHandler)(dmScript::LuaCallbackInfo* onSuccess,
                                 dmScript::LuaCallbackInfo* onFailure,
                                 const int callbackType,
                                 char* data);

void cppHandler(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure, int callbackType, char* data);

using stringFunction = char*();
using voidCallbacksFunction = void(UniversalHandler, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using voidStringCallbacksFunction = void(UniversalHandler, const char* option, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);


int stringGetter(lua_State* L, stringFunction func);
int voidCallbacksGetter(lua_State* L, voidCallbacksFunction func, bool isRequiredFirstCallback);
int voidStringCallbacksGetter(lua_State* L, voidStringCallbacksFunction func, bool isRequiredFirstCallback);

#endif