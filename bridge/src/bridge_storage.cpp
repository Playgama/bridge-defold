#if defined(DM_PLATFORM_HTML5)
#include "bridge_storage.h"
#include "bridge.h"

int bridge::storage::get(lua_State* L) {
    return makeCallbackStorage(L, js_bridge_storage_get, true);
}

int bridge::storage::set(lua_State* L) {
    return makeCallbackStorage(L, js_bridge_storage_set, false);
}

int bridge::storage::deleteData(lua_State* L) {
    return makeCallbackStorage(L, js_bridge_storage_delete, false);
}

#endif
