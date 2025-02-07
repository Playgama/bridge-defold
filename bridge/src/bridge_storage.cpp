#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_storage.h"
#include <dmsdk/dlib/crypt.h>

namespace { // private
    void cpp_bridge_storage_get(dmScript::LuaCallbackInfo* onSuccess,
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

    void cpp_bridge_storage_set(dmScript::LuaCallbackInfo* onSuccess,
                              dmScript::LuaCallbackInfo* onFailure,
                              const int callbackType, char* error) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onSuccess");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                lua_pushstring(L, error);
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
        free(error);
    }

    void cpp_bridge_storage_delete(dmScript::LuaCallbackInfo* onSuccess,
                                 dmScript::LuaCallbackInfo* onFailure,
                                 const int callbackType,
                                 char* error) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onSuccess");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                lua_pushstring(L, error);
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
        free(error);
    }
} // namespace

void bridge::storage::get(const char* json, dmScript::LuaCallbackInfo* onSuccess,
                        dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_storage_get((StoreGetHandler)cpp_bridge_storage_get, json, onSuccess, onFailure, storageType);
}

void bridge::storage::set(const char* json,
                        dmScript::LuaCallbackInfo* onSuccess,
                        dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_storage_set((StoreSetHandler)cpp_bridge_storage_set, json, onSuccess, onFailure, storageType);
}

bool bridge::storage::isSupported(const char* storageType) { return js_bridge_storage_isSupported(storageType); }

bool bridge::storage::isAvailable(const char* storageType) { return js_bridge_storage_isAvailable(storageType); }

char* bridge::storage::defaultType() { return js_bridge_storage_defaultType(); }

void bridge::storage::deleteData(const char* key, dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_storage_delete((StoreDeleteHandler)cpp_bridge_storage_delete, key, onSuccess, onFailure, storageType);
}

#endif