#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
    bool js_bridge_leaderboard_isSupported();
    bool js_bridge_leaderboard_isNativePopupSupported();
    bool js_bridge_leaderboard_isMultipleBoardsSupported();
    bool js_bridge_leaderboard_isSetScoreSupported();
    bool js_bridge_leaderboard_isGetScoreSupported();
    bool js_bridge_leaderboard_isGetEntriesSupported();

    void js_bridge_leaderboard_setScore(UniversalHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_getScore(UniversalHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_getEntries(UniversalHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_showNativePopup(UniversalHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
}

#endif