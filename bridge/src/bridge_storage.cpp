#if defined(DM_PLATFORM_HTML5)
#include "bridge_storage.h"
#include "bridge.h"

int bridge::storage::isSupported(lua_State* L) { return boolStringGetter(L, js_bridge_storage_isSupported); }

int bridge::storage::isAvailable(lua_State* L) { return boolStringGetter(L, js_bridge_storage_isAvailable); }

int bridge::storage::defaultType(lua_State* L) { return stringGetter(L, js_bridge_storage_defaultType); }

int bridge::storage::get(lua_State* L) {
    return storageFunctionGetter(L, js_bridge_storage_get, true);
}

int bridge::storage::set(lua_State* L) {
    return storageFunctionGetter(L, js_bridge_storage_set, false);
}

int bridge::storage::deleteData(lua_State* L) {
    return storageFunctionGetter(L, js_bridge_storage_delete, false);
}

#endif