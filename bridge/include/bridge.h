#pragma once

#include <dmsdk/sdk.h>

namespace bridge {
    namespace platform {
        char* id();
        char* language();
        char* tld();
        char* payload();
        void sendMessage(const char* event, dmScript::LuaCallbackInfo *onSuccess, dmScript::LuaCallbackInfo *onFailure);
        void getServerTime(dmScript::LuaCallbackInfo *onSuccess, dmScript::LuaCallbackInfo *onFailure);
    }

    namespace game {
        void on(const char* eventName, dmScript::LuaCallbackInfo *callback);
    }
}