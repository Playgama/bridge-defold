#if defined(DM_PLATFORM_HTML5)
#include "bridge_social.h"
#include "bridge.h"

// Share
int bridge::social::isShareSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isShareSupported);
}

int bridge::social::share(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_social_share, false);
}

// Join Community
int bridge::social::isJoinCommunitySupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isJoinCommunitySupported);
}

int bridge::social::joinCommunity(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_social_joinCommunity, false);
}

// Invite Friends
int bridge::social::isInviteFriendsSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isInviteFriendsSupported);
}

int bridge::social::inviteFriends(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_social_inviteFriends, false);
}

// Create Post
int bridge::social::isCreatePostSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isCreatePostSupported);
}

int bridge::social::createPost(lua_State* L) {
    return makeCallbackWithJson(L, js_bridge_social_createPost, false);
}

// Add to Favorites
int bridge::social::isAddToFavoritesSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isAddToFavoritesSupported);
}

int bridge::social::addToFavorites(lua_State* L) {
    return makeCallback(L, js_bridge_social_addToFavorites, false);
}

// Add to HomeScreen
int bridge::social::isAddToHomeScreenSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isAddToHomeScreenSupported);
}

int bridge::social::addToHomeScreen(lua_State* L) {
    return makeCallback(L, js_bridge_social_addToHomeScreen, false);
}

// Rate Game
int bridge::social::isRateSupported(lua_State* L) {
    return getBoolean(L, js_bridge_social_isRateSupported);
}

int bridge::social::rate(lua_State* L) {
    return makeCallback(L, js_bridge_social_rate, false);
}

// External Links
int bridge::social::isExternalLinksAllowed(lua_State* L) {
    return getBoolean(L, js_bridge_social_isExternalLinksAllowed);
}

#endif