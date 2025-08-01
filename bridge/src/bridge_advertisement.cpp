#if defined(DM_PLATFORM_HTML5)
#include "bridge_advertisement.h"
#include "bridge.h"

#pragma region Banner
int bridge::advertisement::on(lua_State* L) {
    return makeOnCallback(L, js_bridge_advertisement_on);
}

int bridge::advertisement::isBannerSupported(lua_State* L) {
    return getBoolean(L, js_bridge_advertisement_isBannerSupported);
}

int bridge::advertisement::showBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);

    const char* position = NULL;
    if (lua_isstring(L, 1))
        position = lua_tostring(L, 1);

    const char* placement = NULL;
    if (lua_isstring(L, 2))
        placement = lua_tostring(L, 2);
    
    js_bridge_advertisement_showBanner(position, placement);
    return 0;
}

int bridge::advertisement::bannerState(lua_State* L) {
    return getString(L, js_bridge_advertisement_bannerState);
}

int bridge::advertisement::hideBanner(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    js_bridge_advertisement_hideBanner();
    return 0;
}
#pragma region

#pragma region Interstitial
int bridge::advertisement::isInterstitialSupported(lua_State* L) {
    return getBoolean(L, js_bridge_advertisement_isInterstitialSupported);
}

int bridge::advertisement::showInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);

    const char* placement = NULL;
    if (lua_isstring(L, 1))
        placement = lua_tostring(L, 1);
    
    js_bridge_advertisement_showInterstitial(placement);
    return 0;
}

int bridge::advertisement::minimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 1);
    int delay = js_bridge_advertisement_minimumDelayBetweenInterstitial();
    lua_pushinteger(L, delay);
    return 1;
}

int bridge::advertisement::setMinimumDelayBetweenInterstitial(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    int delay = luaL_checkinteger(L, 1);
    js_bridge_advertisement_setMinimumDelayBetweenInterstitial(delay);
    return 0;
}

int bridge::advertisement::interstitialState(lua_State* L) {
    return getString(L, js_bridge_advertisement_interstitialState);
}
#pragma endregion

#pragma region Rewarded
int bridge::advertisement::isRewardedSupported(lua_State* L) {
    return getBoolean(L, js_bridge_advertisement_isRewardedSupported);
}

int bridge::advertisement::rewardedState(lua_State* L) {
    return getString(L, js_bridge_advertisement_rewardedState);
}

int bridge::advertisement::rewardedPlacement(lua_State* L) {
    return getString(L, js_bridge_advertisement_rewardedPlacement);
}

int bridge::advertisement::showRewarded(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);

    const char* placement = NULL;
    if (lua_isstring(L, 1))
    placement = lua_tostring(L, 1);
    
    js_bridge_advertisement_showRewarded(placement);
    return 0;
}
#pragma endregion

#pragma region Adblock

int bridge::advertisement::checkAdBlock(lua_State* L) {
    return makeCallback(L, js_bridge_advertisement_checkAdBlock, true);
}

#pragma endregion

#endif
