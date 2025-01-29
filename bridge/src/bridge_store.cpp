#include <stdio.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include "bridge_store.h"
#include <dmsdk/dlib/crypt.h>

namespace { // private
    void cpp_bridge_store_get(dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure,
                                     const int callbackType, char* dataOrError) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                uint32_t dataLen = strlen(dataOrError);
                uint32_t dstlen = dataLen * 3 / 4;
                uint8_t* dst = (uint8_t*)malloc(dstlen);
                if (!dmCrypt::Base64Decode((const uint8_t*)dataOrError, dataLen, dst, &dstlen)) {
                    free(dst);
                    dmLogError("Can't decode Base64 string.");
                }
                dmScript::PushTable(L, (const char*)dst, dstlen);
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

    void cpp_bridge_store_set(dmScript::LuaCallbackInfo* onSuccess,
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

    void cpp_bridge_store_delete(dmScript::LuaCallbackInfo* onSuccess,
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

void bridge::store::get(const char* key, dmScript::LuaCallbackInfo* onSuccess,
                        dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_store_get((StoreGetHandler)cpp_bridge_store_get, key, onSuccess, onFailure, storageType);
}

void bridge::store::set(const char* key, const char* value,
                        dmScript::LuaCallbackInfo* onSuccess,
                        dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_store_set((StoreSetHandler)cpp_bridge_store_set, key, value, onSuccess, onFailure, storageType);
}

bool bridge::store::isSupported(const char* storageType) { return js_bridge_store_isSupported(storageType); }

bool bridge::store::isAvailable(const char* storageType) { return js_bridge_store_isAvailable(storageType); }

char* bridge::store::defaultType() { return js_bridge_store_defaultType(); }

void bridge::store::deleteData(const char* key, dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure, const char* storageType) {
    js_bridge_store_delete((StoreDeleteHandler)cpp_bridge_store_delete, key, onSuccess, onFailure, storageType);
}

#endif