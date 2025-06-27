#pragma once

#if defined(DM_PLATFORM_HTML5)
#include <dmsdk/sdk.h>

typedef void (*UniversalHandler)(dmScript::LuaCallbackInfo* onSuccess, // destroy callback by calling
                                 dmScript::LuaCallbackInfo* onFailure,
                                 const int callbackType,
                                 char* data);

typedef void (*OnHandler)(dmScript::LuaCallbackInfo* callback, // not destroy callback by calling
                               char* data);

void cppUniversalHandler(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure, int callbackType, char* data);
void cppOnHandler(dmScript::LuaCallbackInfo* onSuccess, char* data);

using StringFunction = char*();
using BooleanFunction = bool();
using BooleanStringFunction = bool(const char*);
using CallbacksFunction = void(UniversalHandler, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using CallbacksWithStringFunction = void(UniversalHandler, const char* option, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using OnFunction = void(OnHandler handler, const char* eventName, dmScript::LuaCallbackInfo* onSuccess);
using LeaderboardsSetScoreFunction = void(UniversalHandler handler, const char* id, int score, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
using StorageFunction = void(UniversalHandler handler, const char* json, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure, const char* storageType);

int getString(lua_State* L, StringFunction func);
int getBoolean(lua_State* L, BooleanFunction func);
int getBooleanWithString(lua_State* L, BooleanStringFunction func);
int makeCallback(lua_State* L, CallbacksFunction func, bool isRequiredFirstCallback);
int makeCallbackWithString(lua_State* L, CallbacksWithStringFunction func, bool isRequiredFirstCallback);
int makeCallbackWithJson(lua_State* L, CallbacksWithStringFunction func, bool isRequiredFirstCallback);
int makeCallbackStorage(lua_State* L, StorageFunction func, bool isRequiredFirstCallback);
int makeCallbackLeaderboardsSetScore(lua_State* L, LeaderboardsSetScoreFunction func, bool isRequiredFirstCallback);
int makeOnCallback(lua_State* L, OnFunction func);


#endif