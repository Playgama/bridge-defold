#pragma once

#if defined(DM_PLATFORM_HTML5)
#include <dmsdk/sdk.h>

typedef void (*UniversalHandler)(dmScript::LuaCallbackInfo* onSuccess, // destroy callback, by calling
                                 dmScript::LuaCallbackInfo* onFailure,
                                 const int callbackType,
                                 char* data);

typedef void (*RuntimeHandler)(dmScript::LuaCallbackInfo* onSuccess, // not destroy callback, by calling
                               char* data);

void cppUniversalHandler(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure, int callbackType, char* data);
void cppRuntimeHandler(dmScript::LuaCallbackInfo* onSuccess, char* data);

using stringFunction = char*();
using boolFunction = bool();
using voidCallbacksFunction = void(UniversalHandler, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using voidStringCallbacksFunction = void(UniversalHandler, const char* option, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using runtimeOnFunction = void(RuntimeHandler handler, const char* eventName, dmScript::LuaCallbackInfo* onSuccess);

int stringGetter(lua_State* L, stringFunction func);
int boolGetter(lua_State* L, boolFunction func);
int voidCallbacksGetter(lua_State* L, voidCallbacksFunction func, bool isRequiredFirstCallback);
int voidStringCallbacksGetter(lua_State* L, voidStringCallbacksFunction func, bool isRequiredFirstCallback);
int voidJsonCallbacksGetter(lua_State* L, voidStringCallbacksFunction func, bool isRequiredFirstCallback);
int runtimeOnGetter(lua_State* L, runtimeOnFunction func);
#endif