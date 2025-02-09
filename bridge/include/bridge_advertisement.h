#pragma once

#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_HTML5)

typedef void (*AdvertisementOnHandler)(dmScript::LuaCallbackInfo* callback, char* state);

extern "C" {
#pragma region Banner
    bool js_bridge_advertisement_isBannerSupported();

    void js_bridge_advertisement_showBanner(const char* options);

    void js_bridge_advertisement_hideBanner();

    char* js_bridge_advertisement_bannerState();

    void js_bridge_advertisement_on(AdvertisementOnHandler handler,
                                    const char* eventName,
                                    dmScript::LuaCallbackInfo* callback);
#pragma region

#pragma region Interstitial
    int js_bridge_advertisement_minimumDelayBetweenInterstitial();

    void js_bridge_advertisement_setMinimumDelayBetweenInterstitial(int delay);

    char* js_bridge_advertisement_interstitialState();

    void js_bridge_advertisement_showInterstitial();
#pragma endregion

#pragma region Rewarded
    char* js_bridge_advertisement_rewardedState();

    void js_bridge_advertisement_showRewarded();
#pragma endregion
}

#endif