#pragma once

#include <dmsdk/sdk.h>

namespace bridge {
    namespace platform {
        int id(lua_State* L);
        int language(lua_State* L);
        int tld(lua_State* L);
        int payload(lua_State* L);

        int sendMessage(lua_State* L);
        int getServerTime(lua_State* L);
    } // namespace platform

    namespace game {
        int on(lua_State* L);
        int visibilityState(lua_State* L);
    } // namespace game

    namespace storage {
        int defaultType(lua_State* L);
        int isSupported(lua_State* L);
        int isAvailable(lua_State* L);
        int get(lua_State* L);
        int set(lua_State* L);
        int deleteData(lua_State* L);
    } // namespace store

    namespace advertisement {
        // Banner
        int isBannerSupported(lua_State* L);
        int showBanner(lua_State* L);
        int bannerState(lua_State* L);
        int on(lua_State* L);
        int hideBanner(lua_State* L);

        // Interstitial
        int minimumDelayBetweenInterstitial(lua_State* L);
        int setMinimumDelayBetweenInterstitial(lua_State* L);
        int interstitialState(lua_State* L);
        int showInterstitial(lua_State* L);

        int showRewarded(lua_State* L);
        int rewardedState(lua_State* L);

        // AdBlock
        int checkAdBlock(lua_State* L);
    } // namespace advertisement

    namespace device {
        int type(lua_State* L);
    } // namespace device

    namespace player {
        int isAuthorizationSupported(lua_State* L);
        int isAuthorized(lua_State* L);
        int id(lua_State* L);
        int name(lua_State* L);
        int photos(lua_State* L);
        int authorize(lua_State* L);
    } // namespace player

    namespace social {
        // Share
        int isShareSupported(lua_State* L);
        int share(lua_State* L);

        // Join Community
        int isJoinCommunitySupported(lua_State* L);
        int joinCommunity(lua_State* L);

        // Invite Friends
        int isInviteFriendsSupported(lua_State* L);
        int inviteFriends(lua_State* L);

        // Add to Favorites
        int isAddToFavoritesSupported(lua_State* L);
        int addToFavorites(lua_State* L);

        // Create Post
        int isCreatePostSupported(lua_State* L);
        int createPost(lua_State* L);

        //  Add to Favorites
        int isAddToHomeScreenSupported(lua_State* L);
        int addToHomeScreen(lua_State* L);

        // Rate Game
        int isRateSupported(lua_State* L);
        int rate(lua_State* L);

        // External Links
        int isExternalLinksAllowed(lua_State* L);
    } // namespace device

    namespace leaderboards {
        // Support
        int isSupported(lua_State* L);
        int isNativePopupSupported(lua_State* L);
        int isMultipleBoardsSupported(lua_State* L);
        int isSetScoreSupported(lua_State* L);
        int isGetScoreSupported(lua_State* L);
        int isGetEntriesSupported(lua_State* L);

        // Player Scores. Set
        int setScore(lua_State* L);

        // Player Scores. Get
        int getScore(lua_State* L);

        // Get Full Leaderboard
        int getEntries(lua_State* L);

        // Show Native Popup
        int showNativePopup(lua_State* L);
    } // namespace leaderboards

    namespace achievements {
        int isSupported(lua_State* L);
        int isGetListSupported(lua_State* L);
        int isNativePopupSupported(lua_State* L);
        int unlock(lua_State* L);
        int getList(lua_State* L);
        int showNativePopup(lua_State* L);
    } // namespace achievements

    namespace payments {
        bool isSupported();
        bool isGetCatalogSupported();
        bool isGetPurchasesSupported();
        bool isConsumePurchaseSupported();
        void purchase(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
        void consumePurchase(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
        void getCatalog(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
        void getPurchases(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    } // namespace payments

    namespace remoteConfig {
        bool isSupported();
        void get(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    } // namespace remoteConfig

} // namespace bridge