#pragma once

#include <dmsdk/sdk.h>

namespace bridge {
    namespace platform {
        int on(lua_State* L);
        
        int id(lua_State* L);
        int language(lua_State* L);
        int tld(lua_State* L);
        int payload(lua_State* L);

        int sendMessage(lua_State* L);
        int getServerTime(lua_State* L);

        int isAudioEnabled(lua_State* L);

        int isGetAllGamesSupported(lua_State* L);
        int isGetGameByIdSupported(lua_State* L);

        int getAllGames(lua_State* L);
        int getGameById(lua_State* L);
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
        int isInterstitialSupported(lua_State* L);
        int minimumDelayBetweenInterstitial(lua_State* L);
        int setMinimumDelayBetweenInterstitial(lua_State* L);
        int interstitialState(lua_State* L);
        int showInterstitial(lua_State* L);

        int isRewardedSupported(lua_State* L);
        int showRewarded(lua_State* L);
        int rewardedState(lua_State* L);
        int rewardedPlacement(lua_State* L);

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
        int extra(lua_State* L);
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
        int type(lua_State* L);
        int setScore(lua_State* L);
        int getEntries(lua_State* L);
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
        int isSupported(lua_State* L);
        int purchase(lua_State* L);
        int consumePurchase(lua_State* L);
        int getCatalog(lua_State* L);
        int getPurchases(lua_State* L);
    } // namespace payments

    namespace remoteConfig {
        int isSupported(lua_State* L);
        int get(lua_State* L);
    } // namespace remoteConfig

} // namespace bridge