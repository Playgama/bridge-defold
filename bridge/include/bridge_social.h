#pragma once

#if defined(DM_PLATFORM_HTML5)

#include "bridge_helper.h"
#include <dmsdk/sdk.h>

using sss = void(int dsfs);

extern "C" {
    // Share
    bool js_bridge_social_isShareSupported();
    void js_bridge_social_share(UniversalHandler handler,
                                const char* json,
                                dmScript::LuaCallbackInfo* onSuccess,
                                dmScript::LuaCallbackInfo* onFailure);
    // Join Community
    bool js_bridge_social_isJoinCommunitySupported();
    void js_bridge_social_joinCommunity(UniversalHandler handler,
                                        const char* json,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
    // Invite Friends
    bool js_bridge_social_isInviteFriendsSupported();
    void js_bridge_social_inviteFriends(UniversalHandler handler,
                                        const char* json,
                                        dmScript::LuaCallbackInfo* onSuccess,
                                        dmScript::LuaCallbackInfo* onFailure);
    // Add to Favorites
    bool js_bridge_social_isAddToFavoritesSupported();
    void js_bridge_social_addToFavorites(UniversalHandler handler,
                                         dmScript::LuaCallbackInfo* onSuccess,
                                         dmScript::LuaCallbackInfo* onFailure);

    // Create Post
    bool js_bridge_social_isCreatePostSupported();
    void js_bridge_social_createPost(UniversalHandler handler,
                                     const char* json,
                                     dmScript::LuaCallbackInfo* onSuccess,
                                     dmScript::LuaCallbackInfo* onFailure);
    //  Add to Favorites
    bool js_bridge_social_isAddToHomeScreenSupported();
    void js_bridge_social_addToHomeScreen(UniversalHandler handler,
                                          dmScript::LuaCallbackInfo* onSuccess,
                                          dmScript::LuaCallbackInfo* onFailure);
    // Rate Game
    bool js_bridge_social_isRateSupported();
    void js_bridge_social_rate(UniversalHandler handler,
                               dmScript::LuaCallbackInfo* onSuccess,
                               dmScript::LuaCallbackInfo* onFailure);
    // External Links
    bool js_bridge_social_isExternalLinksAllowed();
}

#endif