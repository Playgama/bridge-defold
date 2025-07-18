#pragma once

#if defined(DM_PLATFORM_HTML5)
#include "bridge_helper.h"
#include <dmsdk/sdk.h>

extern "C" {
#pragma region Banner
    bool js_bridge_advertisement_isBannerSupported();

    void js_bridge_advertisement_showBanner(const char* position, const char* placement);

    void js_bridge_advertisement_hideBanner();

    char* js_bridge_advertisement_bannerState();

    void js_bridge_advertisement_on(OnHandler handler,
                                    const char* eventName,
                                    dmScript::LuaCallbackInfo* callback);
#pragma region

#pragma region Interstitial
    bool js_bridge_advertisement_isInterstitialSupported();

    int js_bridge_advertisement_minimumDelayBetweenInterstitial();

    void js_bridge_advertisement_setMinimumDelayBetweenInterstitial(int delay);

    char* js_bridge_advertisement_interstitialState();

    void js_bridge_advertisement_showInterstitial(const char* placement);
#pragma endregion

#pragma region Rewarded
    bool js_bridge_advertisement_isRewardedSupported();

    char* js_bridge_advertisement_rewardedState();

    char* js_bridge_advertisement_rewardedPlacement();

    void js_bridge_advertisement_showRewarded(const char* placement);
#pragma endregion

#pragma region Adblock
    void js_bridge_advertisement_checkAdBlock(UniversalHandler handler,
                                              dmScript::LuaCallbackInfo* onSuccess,
                                              dmScript::LuaCallbackInfo* onFailure);
#pragma endregion
}

#endif