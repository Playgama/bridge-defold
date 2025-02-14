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
        bool isBannerSupported();
        void showBanner(const char* options);
        char* bannerState();
        void on(const char* eventName, dmScript::LuaCallbackInfo* callback);
        void hideBanner();

        // Interstitial
        int minimumDelayBetweenInterstitial();
        void setMinimumDelayBetweenInterstitial(int delay);
        char* interstitialState();
        void showInterstitial();

        void showRewarded();
        char* rewardedState();

        // AdBlock
        void checkAdBlock(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    } // namespace advertisement

    namespace device {
        int type(lua_State* L);
    } // namespace device

    namespace player {
        bool isAuthorizationSupported();
        bool isAuthorized();
        char* id();
        char* name();
        char* photos();
        void authorize(const char* oprions, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
    } // namespace player

    namespace social {
        // Share
        bool isShareSupported();
        void share(
            const char* options,
            dmScript::LuaCallbackInfo* onSuccess,
            dmScript::LuaCallbackInfo* onFailure);
        // Join Community
        bool isJoinCommunitySupported();
        void joinCommunity(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Invite Friends
        bool isInviteFriendsSupported();
        void inviteFriends(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Create Post
        bool isCreatePostSupported();
        void createPost(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        //  Add to Favorites
        bool isAddToHomeScreenSupported();
        void addToHomeScreen(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Rate Game
        bool isRateSupported();
        void rate(dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // External Links
        bool isExternalLinksAllowed();
    } // namespace device

    namespace leaderboards {
        // Support
        bool isSupported();
        bool isNativePopupSupported();
        bool isMultipleBoardsSupported();
        bool isSetScoreSupported();
        bool isGetScoreSupported();
        bool isGetEntriesSupported();

        // Player Scores. Set
        void setScore(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Player Scores. Get
        void getScore(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Get Full Leaderboard
        void getEntries(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);

        // Show Native Popup
        void showNativePopup(const char* options, dmScript::LuaCallbackInfo* onSuccess, dmScript::LuaCallbackInfo* onFailure);
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