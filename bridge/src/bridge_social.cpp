#if defined(DM_PLATFORM_HTML5)
#include "bridge_social.h"
#include "bridge.h"

namespace {
    void cpp_share_handler(dmScript::LuaCallbackInfo* onSuccess,
                           dmScript::LuaCallbackInfo* onFailure, int callbackType) {
        if (callbackType == 0 && dmScript::IsCallbackValid(onSuccess)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onSuccess);
            if (dmScript::SetupCallback(onSuccess)) {
                dmScript::PCall(L, 1, 0);
                dmScript::TeardownCallback(onSuccess);
            } else {
                dmLogError("Failed to setup onOpen");
            }
        }

        if (callbackType == 1 && dmScript::IsCallbackValid(onFailure)) {
            lua_State* L = dmScript::GetCallbackLuaContext(onFailure);
            if (dmScript::SetupCallback(onFailure)) {
                dmScript::PCall(L, 1, 0);
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
    }
}

// Share
bool bridge::social::isShareSupported() {
    return js_bridge_social_isShareSupported();
}
void bridge::social::share(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_share((ShareHandler)cpp_share_handler, options, onSuccess, onFailure);
}

// Join Community
bool bridge::social::isJoinCommunitySupported() {
    return js_bridge_social_isJoinCommunitySupported();
}
void bridge::social::joinCommunity(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_joinCommunity((ShareHandler)cpp_share_handler, options, onSuccess, onFailure);
}

// Invite Friends
bool bridge::social::isInviteFriendsSupported() {
    return js_bridge_social_isInviteFriendsSupported();
}
void bridge::social::inviteFriends(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_inviteFriends((ShareHandler)cpp_share_handler, options, onSuccess, onFailure);
}

// Create Post
bool bridge::social::isCreatePostSupported() {
    return js_bridge_social_isCreatePostSupported();
}
void bridge::social::createPost(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_createPost((ShareHandler)cpp_share_handler, options, onSuccess, onFailure);
}

//  Add to Favorites
bool bridge::social::isAddToHomeScreenSupported() {
    return js_bridge_social_isAddToHomeScreenSupported();
}
void bridge::social::addToHomeScreen(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_addToHomeScreen((ShareHandler)cpp_share_handler, onSuccess, onFailure);
}

// Rate Game
bool bridge::social::isRateSupported() {
    return js_bridge_social_isRateSupported();
}

void bridge::social::rate(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure) {
    js_bridge_social_rate((ShareHandler)cpp_share_handler, onSuccess, onFailure);
}

// External Links
bool bridge::social::isExternalLinksAllowed() {
    return js_bridge_social_isExternalLinksAllowed();
}

#endif