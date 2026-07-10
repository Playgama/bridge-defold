#define LIB_NAME "Bridge"
#define MODULE_NAME "Bridge"
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"

// Functions exposed to Lua
static const luaL_reg platform_methods[] = {
    { "on", bridge::platform::on },
    { "id", bridge::platform::id },
    { "language", bridge::platform::language },
    { "payload", bridge::platform::payload },
    { "tld", bridge::platform::tld },
    { "send_message", bridge::platform::sendMessage },
    { "send_custom_message", bridge::platform::sendCustomMessage },
    { "get_server_time", bridge::platform::getServerTime },
    { "is_audio_enabled", bridge::platform::isAudioEnabled },
    { "is_external_calls_supported", bridge::platform::isExternalCallsSupported },
    { "is_external_links_allowed", bridge::platform::isExternalLinksAllowed },
    { 0, 0 }
};

static const luaL_reg cross_promo_methods[] = {
    { "get_games", bridge::crossPromo::getGames },
    { "show", bridge::crossPromo::show },
    { "hide", bridge::crossPromo::hide },
    { "is_visible", bridge::crossPromo::isVisible },
    { 0, 0 }
};

static const luaL_reg storage_methods[] = {
    { "get", bridge::storage::get },
    { "set", bridge::storage::set },
    { "delete", bridge::storage::deleteData },
    { 0, 0 }
};

static const luaL_reg advertisement_methods[] = {
    // Banner
    { "show_banner", bridge::advertisement::showBanner },
    { "hide_banner", bridge::advertisement::hideBanner },
    { "banner_state", bridge::advertisement::bannerState },
    { "is_banner_supported", bridge::advertisement::isBannerSupported },
    { "on", bridge::advertisement::on },

    // Interstitial
    { "is_interstitial_supported", bridge::advertisement::isInterstitialSupported },
    { "show_interstitial", bridge::advertisement::showInterstitial },
    { "minimum_delay_between_interstitial", bridge::advertisement::minimumDelayBetweenInterstitial },
    { "set_minimum_delay_between_interstitial", bridge::advertisement::setMinimumDelayBetweenInterstitial },
    { "interstitial_state", bridge::advertisement::interstitialState },

    // Rewarded
    { "is_rewarded_supported", bridge::advertisement::isRewardedSupported },
    { "rewarded_state", bridge::advertisement::rewardedState },
    { "rewarded_placement", bridge::advertisement::rewardedPlacement },
    { "show_rewarded", bridge::advertisement::showRewarded },

    // Advanced Banners
    { "is_advanced_banners_supported", bridge::advertisement::isAdvancedBannersSupported },
    { "advanced_banners_state", bridge::advertisement::advancedBannersState },
    { "show_advanced_banners", bridge::advertisement::showAdvancedBanners },
    { "hide_advanced_banners", bridge::advertisement::hideAdvancedBanners },

    // Ad Block
    { "check_ad_block", bridge::advertisement::checkAdBlock },
    { 0, 0 }
};

static const luaL_reg device_methods[] = {
    { "type", bridge::device::type },
    { 0, 0 }
};

static const luaL_reg player_methods[] = {
    { "id", bridge::player::id },
    { "name", bridge::player::name },
    { "extra", bridge::player::extra },
    { "photos", bridge::player::photos },
    { "is_authorization_supported", bridge::player::isAuthorizationSupported },
    { "is_authorized", bridge::player::isAuthorized },
    { "is_guest", bridge::player::isGuest },
    { "authorize", bridge::player::authorize },
    { 0, 0 }
};

static const luaL_reg social_methods[] = {
    // Share
    { "is_share_supported", bridge::social::isShareSupported },
    { "share", bridge::social::share },

    // Join Community
    { "is_join_community_supported", bridge::social::isJoinCommunitySupported },
    { "join_community", bridge::social::joinCommunity },

    // Invite Friends
    { "is_invite_friends_supported", bridge::social::isInviteFriendsSupported },
    { "invite_friends", bridge::social::inviteFriends },

    // Create Post
    { "is_create_post_supported", bridge::social::isCreatePostSupported },
    { "create_post", bridge::social::createPost },

    //  Add to Home Screen
    { "is_add_to_home_screen_supported", bridge::social::isAddToHomeScreenSupported },
    { "add_to_home_screen", bridge::social::addToHomeScreen },

    // Add to Favorites
    { "is_add_to_favorites_supported", bridge::social::isAddToFavoritesSupported },
    { "add_to_favorites", bridge::social::addToFavorites },

    // Rate Game
    { "is_rate_supported", bridge::social::isRateSupported },
    { "rate", bridge::social::rate },
    { 0, 0 }
};

static const luaL_reg leaderboards_methods[] = {
    { "type", bridge::leaderboards::type },
    { "set_score", bridge::leaderboards::setScore },
    { "get_entries", bridge::leaderboards::getEntries },
    { "show_native_popup", bridge::leaderboards::showNativePopup },
    { 0, 0 }
};

static const luaL_reg achievements_methods[] = {
    { "unlock", bridge::achievements::unlock },
    { "get_achievements", bridge::achievements::getAchievements },
    { 0, 0 }
};

static const luaL_reg tasks_methods[] = {
    { "get_tasks", bridge::tasks::getTasks },
    { "add_progress", bridge::tasks::addProgress },
    { "claim_reward", bridge::tasks::claimReward },
    { 0, 0 }
};

static const luaL_reg daily_rewards_methods[] = {
    { "get_rewards", bridge::dailyRewards::getRewards },
    { "get_current_day", bridge::dailyRewards::getCurrentDay },
    { "get_current_reward", bridge::dailyRewards::getCurrentReward },
    { "claim_current_reward", bridge::dailyRewards::claimCurrentReward },
    { 0, 0 }
};

static const luaL_reg payments_methods[] = {
    { "is_supported", bridge::payments::isSupported },
    { "purchase", bridge::payments::purchase },
    { "consume_purchase", bridge::payments::consumePurchase },
    { "get_catalog", bridge::payments::getCatalog },
    { "get_purchases", bridge::payments::getPurchases },
    { 0, 0 }
};

static const luaL_reg remoteConfig_methods[] = {
    { "is_supported", bridge::remoteConfig::isSupported },
    { "set_context", bridge::remoteConfig::setContext },
    { "get", bridge::remoteConfig::get },
    { 0, 0 }
};

#endif

#pragma region Defold
static void LuaInit(lua_State* L) {
    int top = lua_gettop(L);
#if defined(DM_PLATFORM_HTML5)

    lua_newtable(L); // create _bridge table (root)
    lua_pushvalue(L, -1);
    lua_setglobal(L, "_bridge");
    {
        lua_pushstring(L, "platform"); // create platform table
        lua_newtable(L);
        luaL_register(L, NULL, platform_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "cross_promo"); // create cross_promo table
        lua_newtable(L);
        luaL_register(L, NULL, cross_promo_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "storage"); // create storage table
        lua_newtable(L);
        luaL_register(L, NULL, storage_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "advertisement"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, advertisement_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "device"); // create device table
        lua_newtable(L);
        luaL_register(L, NULL, device_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "player"); // create player table
        lua_newtable(L);
        luaL_register(L, NULL, player_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "social"); // create social table
        lua_newtable(L);
        luaL_register(L, NULL, social_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "leaderboards"); // create leaderboards table
        lua_newtable(L);
        luaL_register(L, NULL, leaderboards_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "achievements"); // create achievements table
        lua_newtable(L);
        luaL_register(L, NULL, achievements_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "tasks"); // create tasks table
        lua_newtable(L);
        luaL_register(L, NULL, tasks_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "daily_rewards"); // create daily_rewards table
        lua_newtable(L);
        luaL_register(L, NULL, daily_rewards_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "payments"); // create payments table
        lua_newtable(L);
        luaL_register(L, NULL, payments_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "remote_config"); // create remote_config table
        lua_newtable(L);
        luaL_register(L, NULL, remoteConfig_methods);
        lua_settable(L, -3);
    }
    lua_pop(L, 1);
#endif
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializeMyExtension(dmExtension::Params* params) {
    // Init Lua
    LuaInit(params->m_L);
    printf("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(Bridge, LIB_NAME, 0, 0, InitializeMyExtension, 0, 0, 0)
#pragma endregion
