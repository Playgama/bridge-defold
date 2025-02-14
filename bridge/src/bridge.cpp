// myextension.cpp
// Extension lib defines
#define LIB_NAME "Bridge"
#define MODULE_NAME "Bridge"
// include the Defold SDK

#if defined(DM_PLATFORM_HTML5)
#include "bridge.h"
#include <stdio.h>


#pragma region Leaderboards

static int bridge_leaderboards_isGetEntriesSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isGetEntriesSupported = bridge::leaderboards::isGetEntriesSupported();
    lua_pushboolean(L, isGetEntriesSupported);
    return 1;
}

static int bridge_leaderboards_isGetScoreSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isGetScoreSupported = bridge::leaderboards::isGetScoreSupported();
    lua_pushboolean(L, isGetScoreSupported);
    return 1;
}

static int bridge_leaderboards_isMultipleBoardsSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isMultipleBoardsSupported = bridge::leaderboards::isMultipleBoardsSupported();
    lua_pushboolean(L, isMultipleBoardsSupported);
    return 1;
}

static int bridge_leaderboards_isNativePopupSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isNativePopupSupported = bridge::leaderboards::isNativePopupSupported();
    lua_pushboolean(L, isNativePopupSupported);
    return 1;
}

static int bridge_leaderboards_isSetScoreSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSetScoreSupported = bridge::leaderboards::isSetScoreSupported();
    lua_pushboolean(L, isSetScoreSupported);
    return 1;
}

static int bridge_leaderboards_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSupported = bridge::leaderboards::isSupported();
    lua_pushboolean(L, isSupported);
    return 1;
}

static int bridge_leaderboards_setScore(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::leaderboards::setScore(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_leaderboards_getScore(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::leaderboards::getScore(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_leaderboards_getEntries(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::leaderboards::getEntries(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_leaderboards_showNativePopup(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::leaderboards::showNativePopup(json, onSuccess, onFailure);
    free(json);
    return 0;
}

#pragma endregion

#pragma region Payments

static int bridge_payments_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSupported = bridge::payments::isSupported();
    lua_pushboolean(L, isSupported);
    return 1;
}

static int bridge_payments_isGetPurchasesSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isGetPurchasesSupported = bridge::payments::isGetPurchasesSupported();
    lua_pushboolean(L, isGetPurchasesSupported);
    return 1;
}

static int bridge_payments_isGetCatalogSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isGetCatalogSupported = bridge::payments::isGetCatalogSupported();
    lua_pushboolean(L, isGetCatalogSupported);
    return 1;
}

static int bridge_payments_isConsumePurchaseSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isConsumePurchaseSupported = bridge::payments::isConsumePurchaseSupported();
    lua_pushboolean(L, isConsumePurchaseSupported);
    return 1;
}

static int bridge_payments_purchase(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::payments::purchase(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_payments_consumePurchase(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::payments::consumePurchase(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_payments_getCatalog(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::payments::getCatalog(onSuccess, onFailure);
    return 0;
}

static int bridge_payments_getPurchases(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::payments::getPurchases(onSuccess, onFailure);
    return 0;
}
#pragma endregion

#pragma region RemoteConfig

static int bridge_remoteConfig_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSupported = bridge::remoteConfig::isSupported();
    lua_pushboolean(L, isSupported);
    return 1;
}

static int bridge_remoteConfig_get(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    bridge::remoteConfig::get(json, onSuccess, onFailure);
    free(json);
    return 0;
}

#pragma endregion

// Functions exposed to Lua
static const luaL_reg platform_methods[] = {
    { "id", bridge::platform::id },
    { "language", bridge::platform::language },
    { "payload", bridge::platform::payload },
    { "tld", bridge::platform::tld },
    { "send_message", bridge::platform::sendMessage },
    { "get_server_time", bridge::platform::getServerTime },
    { 0, 0 }
};

static const luaL_reg game_methods[] = {
    { "on", bridge::game::on },
    { "visibility_state", bridge::game::visibilityState },
    { 0, 0 }
};

static const luaL_reg store_methods[] = {
    { "default_type", bridge::storage::defaultType },
    { "is_supported", bridge::storage::isSupported },
    { "is_available", bridge::storage::isAvailable },
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
    { "show_interstitial", bridge::advertisement::showInterstitial },
    { "minimum_delay_between_interstitial", bridge::advertisement::minimumDelayBetweenInterstitial },
    { "set_minimum_delay_between_interstitial", bridge::advertisement::setMinimumDelayBetweenInterstitial },
    { "interstitial_state", bridge::advertisement::interstitialState },

    // Rewarded
    { "rewarded_state", bridge::advertisement::rewardedState },
    { "show_rewarded", bridge::advertisement::showRewarded },
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
    { "photos", bridge::player::photos },
    { "is_authorization_supported", bridge::player::isAuthorizationSupported },
    { "is_authorized", bridge::player::isAuthorized },
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
    { "createPost", bridge::social::createPost },

    //  Add to Home Screen
    { "is_add_to_home_screen_supported", bridge::social::isAddToHomeScreenSupported },
    { "add_to_home_screen", bridge::social::addToHomeScreen },

    // Add to Favorites
    { "is_add_to_favorites_supported", bridge::social::isAddToFavoritesSupported },
    { "add_to_favorites", bridge::social::addToFavorites },

    // Rate Game
    { "is_rate_supported", bridge::social::isRateSupported },
    { "rate", bridge::social::rate },

    // External Links
    { "is_external_links_allowed", bridge::social::isExternalLinksAllowed },
    { 0, 0 }
};

static const luaL_reg leaderboards_methods[] = {
    { "is_supported", bridge_leaderboards_isSupported },
    { "is_native_popup_supported", bridge_leaderboards_isNativePopupSupported },
    { "is_multiple_boards_supported", bridge_leaderboards_isMultipleBoardsSupported },
    { "is_set_score_supported", bridge_leaderboards_isSetScoreSupported },
    { "is_get_score_supported", bridge_leaderboards_isGetScoreSupported },
    { "is_get_entries_supported", bridge_leaderboards_isGetEntriesSupported },
    { "set_score", bridge_leaderboards_setScore },
    { "get_score", bridge_leaderboards_getScore },
    { "get_entries", bridge_leaderboards_getEntries },
    { "show_native_popup", bridge_leaderboards_showNativePopup },
    { 0, 0 }
};

static const luaL_reg achievements_methods[] = {
    { "is_supported", bridge::achievements::isSupported },
    { "is_get_list_supported", bridge::achievements::isGetListSupported },
    { "is_native_popup_supported", bridge::achievements::isNativePopupSupported },
    { "unlock", bridge::achievements::unlock },
    { "get_list", bridge::achievements::getList },
    { "show_native_popup", bridge::achievements::showNativePopup },
    { 0, 0 }
};

static const luaL_reg payments_methods[] = {
    { "is_supported", bridge_payments_isSupported },
    { "is_get_catalog_supported", bridge_payments_isGetCatalogSupported },
    { "is_get_purchases_supported", bridge_payments_isGetPurchasesSupported },
    { "is_consume_purchase_supported", bridge_payments_isConsumePurchaseSupported },
    { "purchase", bridge_payments_purchase },
    { "consume_purchase", bridge_payments_consumePurchase },
    { "get_catalog", bridge_payments_getCatalog },
    { "get_purchases", bridge_payments_getPurchases },
    { 0, 0 }
};

static const luaL_reg remoteConfig_methods[] = {
    { "is_supported", bridge_remoteConfig_isSupported },
    { "get", bridge_remoteConfig_get },
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

        lua_pushstring(L, "game"); // create game table
        lua_newtable(L);
        luaL_register(L, NULL, game_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "storage"); // create storage table
        lua_newtable(L);
        luaL_register(L, NULL, store_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "advertisement"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, advertisement_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "device"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, device_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "player"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, player_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "social"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, social_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "leaderboards"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, leaderboards_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "achievements"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, achievements_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "payments"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, payments_methods);
        lua_settable(L, -3);

        lua_pushstring(L, "remote_config"); // create advertisement table
        lua_newtable(L);
        luaL_register(L, NULL, remoteConfig_methods);
        lua_settable(L, -3);
    }
    lua_pop(L, 1);
#endif
    // if(luaL_dostring(L, "bridge = require \"bridge.res.common.bridge_mock\"") != 0) {
    //     dmLogError("%s", lua_tostring(L, -1));
    // }
    // lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeMyExtension(dmExtension::AppParams* params) {
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeMyExtension(dmExtension::Params* params) {
    // Init LuaÍ
    LuaInit(params->m_L);
    printf("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeMyExtension(dmExtension::AppParams* params) {
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeMyExtension(dmExtension::Params* params) {
    return dmExtension::RESULT_OK;
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update,
// on_event, final)

// MyExtension is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
#pragma endregion
DM_DECLARE_EXTENSION(Bridge, LIB_NAME, AppInitializeMyExtension,
                     AppFinalizeMyExtension, InitializeMyExtension, 0, 0,
                     FinalizeMyExtension)