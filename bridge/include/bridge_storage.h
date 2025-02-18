#pragma once

#if defined(DM_PLATFORM_HTML5)

#include <bridge_helper.h>
#include <dmsdk/sdk.h>

extern "C" {
    char* js_bridge_storage_defaultType();

    bool js_bridge_storage_isAvailable(const char* storageType);

    bool js_bridge_storage_isSupported(const char* storageType);

    void js_bridge_storage_get(UniversalHandler handler,
                               const char* json,
                               dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure,
                               const char* storageType);

    void js_bridge_storage_set(UniversalHandler handler,
                               const char* json,
                               dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure,
                               const char* storageType);

    void js_bridge_storage_delete(UniversalHandler handler,
                                  const char* json,
                                  dmScript::LuaCallbackInfo* onSuccess,
                                  dmScript::LuaCallbackInfo* onFailure,
                                  const char* storageType);
}

#endif