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
    } // namespace platformÍ

    namespace game {
        void on(const char* eventName, dmScript::LuaCallbackInfo* callback);
        char* visibilityState();
    }

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
     }
} // namespace bridge