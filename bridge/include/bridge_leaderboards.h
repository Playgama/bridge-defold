#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*SetDataHandler)(dmScript::LuaCallbackInfo* onSuccess,
                                dmScript::LuaCallbackInfo* onFailure,
                                const int callbackType);

typedef void (*GetDataHandler)(dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure,
                               const int callbackType,
                               char* dataOrError);

extern "C" {
    bool js_bridge_leaderboard_isSupported();
    bool js_bridge_leaderboard_isNativePopupSupported();
    bool js_bridge_leaderboard_isMultipleBoardsSupported();
    bool js_bridge_leaderboard_isSetScoreSupported();
    bool js_bridge_leaderboard_isGetScoreSupported();
    bool js_bridge_leaderboard_isGetEntriesSupported();

    void js_bridge_leaderboard_setScore(SetDataHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_getScore(GetDataHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_getEntries(GetDataHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    void js_bridge_leaderboard_showNativePopup(SetDataHandler handler, const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
}

#endif