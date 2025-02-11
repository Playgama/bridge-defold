#pragma once

#include <dmsdk/sdk.h>

namespace bridge {
    namespace platform {
        char* id();
        char* language();
        char* tld();
        char* payload();

        void sendMessage(const char* event, dmScript::LuaCallbackInfo* onSuccess,
                         dmScript::LuaCallbackInfo* onFailure);
        void getServerTime(dmScript::LuaCallbackInfo* onSuccess,
                           dmScript::LuaCallbackInfo* onFailure);
    } // namespace platform

    namespace game {
        void on(const char* eventName, dmScript::LuaCallbackInfo* callback);
        char* visibilityState();
    } // namespace game

    namespace storage {
        char* defaultType();
        bool isSupported(const char* storageType);
        bool isAvailable(const char* storageType);
        void get(const char* key, dmScript::LuaCallbackInfo* onSuccess,
                 dmScript::LuaCallbackInfo* onFailure, const char* storageType);
        void set(const char* json,
                 dmScript::LuaCallbackInfo* onSuccess,
                 dmScript::LuaCallbackInfo* onFailure, const char* storageType);
        void deleteData(const char* key, dmScript::LuaCallbackInfo* onSuccess,
                        dmScript::LuaCallbackInfo* onFailure, const char* storageType);
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
        char* type();
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

} // namespace bridge