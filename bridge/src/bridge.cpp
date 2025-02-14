// myextension.cpp
// Extension lib defines
#define LIB_NAME "Bridge"
#define MODULE_NAME "Bridge"
// include the Defold SDK

#if defined(DM_PLATFORM_HTML5)
#include "bridge_platform.h"
#endif
#include <stdio.h>

#include "bridge.h"
#include <dmsdk/dlib/crypt.h>

#if defined(DM_PLATFORM_HTML5)

#pragma region Game

static int bridge_game_on(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);

    bridge::game::on(event_name, callback);
    return 0;
}

static int bridge_game_visibilityState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::game::visibilityState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}
#pragma endregion

#pragma region Storage

static int bridge_storage_isAvailable(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    const char* storageType = luaL_checkstring(L, 1);
    bool isAvailable = bridge::storage::isAvailable(storageType);
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_storage_defaultType(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* defaultType = bridge::storage::defaultType();
    lua_pushstring(L, defaultType);
    free(defaultType);
    return 1;
}

static int bridge_storage_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    const char* storageType = luaL_checkstring(L, 1);
    bool isAvailable = bridge::storage::isSupported(storageType);
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_storage_get(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    // const char* key = luaL_checkstring(L, 1);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;
    onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::get(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}

static int bridge_storage_set(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table

    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    // assert(res < 0);

    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::set(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}

static int bridege_storage_delete(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;
    const char* storageType = NULL;

    if (lua_isfunction(L, 2))
        onSuccess = dmScript::CreateCallback(L, 2);

    if (lua_isfunction(L, 3))
        onFailure = dmScript::CreateCallback(L, 3);

    if (lua_isstring(L, 4))
        storageType = lua_tostring(L, 4);

    bridge::storage::deleteData(json, onSuccess, onFailure, storageType);
    free(json);
    return 0;
}
#pragma endregion

#pragma region Advertisement

static int bridege_advertisement_showBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    luaL_checktype(L, 1, LUA_TTABLE); // table
    char* json;
    size_t json_len;
    int res = dmScript::LuaToJson(L, &json, &json_len);

    bridge::advertisement::showBanner(json);
    free(json);
    return 0;
}

static int bridege_advertisement_hideBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::hideBanner();
    return 0;
}

static int bridge_advertisement_bannerState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::bannerState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_isBannerSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isAvailable = bridge::advertisement::isBannerSupported();
    lua_pushboolean(L, isAvailable);
    return 1;
}

static int bridge_advertisement_on(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* callback = NULL;
    const char* event_name = luaL_checkstring(L, 1);
    callback = dmScript::CreateCallback(L, 2);
    bridge::advertisement::on(event_name, callback);
    return 0;
}

static int bridge_advertisement_showInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::showInterstitial();
    return 0;
}

static int bridge_advertisement_minimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    int delay = bridge::advertisement::minimumDelayBetweenInterstitial();
    lua_pushinteger(L, delay);
    return 1;
}

static int bridge_advertisement_setMinimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    int delay = luaL_checkinteger(L, 1);
    bridge::advertisement::setMinimumDelayBetweenInterstitial(delay);
    return 0;
}

static int bridge_advertisement_interstitialState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::interstitialState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_rewardedState(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::advertisement::rewardedState();
    lua_pushstring(L, str);
    free(str);
    return 1;
}

static int bridge_advertisement_showRewarded(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    bridge::advertisement::showRewarded();
    return 0;
}

static int bridge_advertisement_checkAdBlock(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::advertisement::checkAdBlock(onSuccess, onFailure);
    return 0;
}

#pragma endregion

#pragma region Device

static int bridge_device_type(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* str = bridge::device::type();
    lua_pushstring(L, str);
    free(str);
    return 1;
}
#pragma endregion

#pragma region Player

static int bridge_player_isAuthorizationSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSupported = bridge::player::isAuthorizationSupported();
    lua_pushboolean(L, isSupported);
    return 1;
}

static int bridge_player_isAuthorized(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isAuthorized = bridge::player::isAuthorized();
    lua_pushboolean(L, isAuthorized);
    return 1;
}

static int bridge_player_id(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* id = bridge::player::id();
    lua_pushstring(L, id);
    free(id);
    return 1;
}

static int bridge_player_name(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* name = bridge::player::name();
    lua_pushstring(L, name);
    free(name);
    return 1;
}

static int bridge_player_photos(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    char* photosJson = bridge::player::photos();
    dmScript::JsonToLua(L, photosJson, strlen(photosJson));
    free(photosJson);
    return 1;
}

static int bridge_player_authorize(lua_State* L) {
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

    bridge::player::authorize(json, onSuccess, onFailure);
    free(json);
    return 0;
}

#pragma endregion

#pragma region Social

static int bridge_social_isShareSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isShareSupported = bridge::social::isShareSupported();
    lua_pushboolean(L, isShareSupported);
    return 1;
}

static int bridge_social_share(lua_State* L) {
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

    bridge::social::share(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_social_isJoinCommunitySupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isJoinCommunitySupported = bridge::social::isJoinCommunitySupported();
    lua_pushboolean(L, isJoinCommunitySupported);
    return 1;
}

static int bridge_social_joinCommunity(lua_State* L) {
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

    bridge::social::joinCommunity(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_social_isInviteFriendsSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isInviteFriendsSupported = bridge::social::isInviteFriendsSupported();
    lua_pushboolean(L, isInviteFriendsSupported);
    return 1;
}

static int bridge_social_inviteFriends(lua_State* L) {
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

    bridge::social::inviteFriends(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_social_isCreatePostSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isCreatePostSupported = bridge::social::isCreatePostSupported();
    lua_pushboolean(L, isCreatePostSupported);
    return 1;
}

static int bridge_social_createPost(lua_State* L) {
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

    bridge::social::createPost(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_social_isAddToHomeScreenSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isAddToHomeScreenSupported = bridge::social::isAddToHomeScreenSupported();
    lua_pushboolean(L, isAddToHomeScreenSupported);
    return 1;
}

static int bridge_social_addToHomeScreen(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::social::addToHomeScreen(onSuccess, onFailure);
    return 0;
}

static int bridge_social_isRateSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isRateSupported = bridge::social::isRateSupported();
    lua_pushboolean(L, isRateSupported);
    return 1;
}

static int bridge_social_rate(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    dmScript::LuaCallbackInfo* onSuccess = NULL;
    dmScript::LuaCallbackInfo* onFailure = NULL;

    if (lua_isfunction(L, 1))
        onSuccess = dmScript::CreateCallback(L, 1);

    if (lua_isfunction(L, 2))
        onFailure = dmScript::CreateCallback(L, 2);

    bridge::social::rate(onSuccess, onFailure);
    return 0;
}

static int bridge_social_isExternalLinksAllowed(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isExternalLinksAllowed = bridge::social::isExternalLinksAllowed();
    lua_pushboolean(L, isExternalLinksAllowed);
    return 1;
}

#pragma endregion

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

#pragma region Advertisement

static int bridge_achievements_isSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isSupported = bridge::achievements::isSupported();
    lua_pushboolean(L, isSupported);
    return 1;
}

static int bridge_achievements_isGetListSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isGetListSupported = bridge::achievements::isGetListSupported();
    lua_pushboolean(L, isGetListSupported);
    return 1;
}

static int bridge_achievements_isNativePopupSupported(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    bool isNativePopupSupported = bridge::achievements::isNativePopupSupported();
    lua_pushboolean(L, isNativePopupSupported);
    return 1;
}

static int bridge_achievements_showNativePopup(lua_State* L) {
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

    bridge::achievements::showNativePopup(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_achievements_getList(lua_State* L) {
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

    bridge::achievements::getList(json, onSuccess, onFailure);
    free(json);
    return 0;
}

static int bridge_achievements_unlock(lua_State* L) {
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

    bridge::achievements::unlock(json, onSuccess, onFailure);
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
    { "language", bridge::platform::language},
    { "payload", bridge::platform::payload },
    { "tld", bridge::platform::tld },
    { "send_message", bridge::platform::sendMessage },
    { "get_server_time", bridge::platform::getServerTime },
    { 0, 0 }
};

static const luaL_reg game_methods[] = {
    { "on", bridge_game_on },
    { "visibility_state", bridge_game_visibilityState },
    { 0, 0 }
};

static const luaL_reg store_methods[] = {
    { "default_type", bridge_storage_defaultType },
    { "is_supported", bridge_storage_isSupported },
    { "is_available", bridge_storage_isAvailable },
    { "get", bridge_storage_get },
    { "set", bridge_storage_set },
    { "delete", bridege_storage_delete },
    { 0, 0 }
};

static const luaL_reg advertisement_methods[] = {
    // Banner
    { "show_banner", bridege_advertisement_showBanner },
    { "hide_banner", bridege_advertisement_hideBanner },
    { "banner_state", bridge_advertisement_bannerState },
    { "is_banner_supported", bridge_advertisement_isBannerSupported },
    { "on", bridge_advertisement_on },

    // Interstitial
    { "show_interstitial", bridge_advertisement_showInterstitial },
    { "minimum_delay_between_interstitial", bridge_advertisement_minimumDelayBetweenInterstitial },
    { "set_minimum_delay_between_interstitial", bridge_advertisement_setMinimumDelayBetweenInterstitial },
    { "interstitial_state", bridge_advertisement_interstitialState },

    // Rewarded
    { "rewarded_state", bridge_advertisement_rewardedState },
    { "show_rewarded", bridge_advertisement_showRewarded },
    { "check_ad_block", bridge_advertisement_checkAdBlock },
    { 0, 0 }
};

static const luaL_reg device_methods[] = {
    { "type", bridge_device_type },
    { 0, 0 }
};

static const luaL_reg player_methods[] = {
    { "id", bridge_player_id },
    { "name", bridge_player_name },
    { "photos", bridge_player_photos },
    { "is_authorization_supported", bridge_player_isAuthorizationSupported },
    { "is_authorized", bridge_player_isAuthorized },
    { "authorize", bridge_player_authorize },
    { 0, 0 }
};

static const luaL_reg social_methods[] = {
    // Share
    { "is_share_supported", bridge_social_isShareSupported },
    { "share", bridge_social_share },

    // Join Community
    { "is_join_community_supported", bridge_social_isJoinCommunitySupported },
    { "join_community", bridge_social_joinCommunity },

    // Invite Friends
    { "is_invite_friends_supported", bridge_social_isInviteFriendsSupported },
    { "invite_friends", bridge_social_inviteFriends },

    // Create Post
    { "is_create_post_supported", bridge_social_isCreatePostSupported },
    { "createPost", bridge_social_createPost },

    //  Add to Favorites
    { "is_add_to_home_screen_supported", bridge_social_isAddToHomeScreenSupported },
    { "add_to_home_screen", bridge_social_addToHomeScreen },

    // Rate Game
    { "is_rate_supported", bridge_social_isRateSupported },
    { "rate", bridge_social_rate },

    // External Links
    { "is_external_links_allowed", bridge_social_isExternalLinksAllowed },
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
    { "is_supported", bridge_achievements_isSupported },
    { "is_get_list_supported", bridge_achievements_isGetListSupported },
    { "is_native_popup_supported", bridge_achievements_isNativePopupSupported },
    { "unlock", bridge_achievements_unlock },
    { "get_list", bridge_achievements_getList },
    { "show_native_popup", bridge_achievements_showNativePopup },
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