#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    char* js_bridge_leaderboards_type();

    void js_bridge_leaderboards_setScore(UniversalHandler handler, const char* id, int score, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboards_getEntries(UniversalHandler handler, const char* id, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboards_showNativePopup(UniversalHandler handler, const char* id, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
}

#endif