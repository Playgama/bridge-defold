#if defined(DM_PLATFORM_HTML5)

#include "bridge_advertisement.h"
#include "bridge.h"

namespace { // private
    void cpp_bridge_advertisement_on(dmScript::LuaCallbackInfo* callback, char* state) {
        if (!dmScript::IsCallbackValid(callback)) {
            return;
        }

        lua_State* L = dmScript::GetCallbackLuaContext(callback);
        if (dmScript::SetupCallback(callback)) {
            lua_pushstring(L, state);
            dmScript::PCall(L, 2, 0);
            dmScript::TeardownCallback(callback);
        } else {
            dmLogError("cpp_bridge_advertisement_on Failed to setup callback");
        }
        free(state);
    }
} // namespace

#pragma region Banner
void bridge::advertisement::on(const char* eventName, dmScript::LuaCallbackInfo* callback) {
    js_bridge_advertisement_on((AdvertisementOnHandler)cpp_bridge_advertisement_on, eventName, callback);
}

bool bridge::advertisement::isBannerSupported() {
    return js_bridge_advertisement_isBannerSupported();
}

void bridge::advertisement::showBanner(const char* options) {
    js_bridge_advertisement_showBanner(options);
}

char* bridge::advertisement::bannerState() {
    return js_bridge_advertisement_bannerState();
}

void bridge::advertisement::hideBanner() {
    js_bridge_advertisement_hideBanner();
}
#pragma region

#pragma region Interstitial
void bridge::advertisement::showInterstitial() {
    js_bridge_advertisement_showInterstitial();
}

int bridge::advertisement::minimumDelayBetweenInterstitial() {
    return js_bridge_advertisement_minimumDelayBetweenInterstitial();
}

void bridge::advertisement::setMinimumDelayBetweenInterstitial(int delay) {
    js_bridge_advertisement_setMinimumDelayBetweenInterstitial(delay);
}

char* bridge::advertisement::interstitialState() {
    return js_bridge_advertisement_interstitialState();
}
#pragma endregion

#pragma region Rewarded
char* bridge::advertisement::rewardedState() {
    return js_bridge_advertisement_rewardedState();
}
void bridge::advertisement::showRewarded() {
    js_bridge_advertisement_showRewarded();
}
#pragma endregion

#endif