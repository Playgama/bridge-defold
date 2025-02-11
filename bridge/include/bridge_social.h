#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*ShareHandler)(dmScript::LuaCallbackInfo* onSuccess,
                             dmScript::LuaCallbackInfo* onFailure,
                             const int callbackType);

using sss = void(int dsfs);

extern "C" {
    // Share
    bool js_bridge_social_isShareSupported();
    void js_bridge_social_share(ShareHandler handler,
                                const char* options,
                                dmScript::LuaCallbackInfo* onSuccess,
                                dmScript::LuaCallbackInfo* onFailure);
    // Join Community
    bool js_bridge_social_isJoinCommunitySupported();
    void js_bridge_social_joinCommunity(ShareHandler handler,
                                        const char* options,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
    // Invite Friends
    bool js_bridge_social_isInviteFriendsSupported();
    void js_bridge_social_inviteFriends(ShareHandler handler,
                                        const char* options,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
    // Create Post
    bool js_bridge_social_isCreatePostSupported();
    void js_bridge_social_createPost(ShareHandler handler,
                                     const char* options,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);
    //  Add to Favorites
    bool js_bridge_social_isAddToHomeScreenSupported();
    void js_bridge_social_addToHomeScreen(ShareHandler handler,
                                          dmScript::LuaCallbackInfo* onSuccess,
                                          dmScript::LuaCallbackInfo* onFailure);
    // Rate Game
    bool js_bridge_social_isRateSupported();
    void js_bridge_social_rate(ShareHandler handler,
                               dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure);
    // External Links
    bool js_bridge_social_isExternalLinksAllowed();
}

#endif