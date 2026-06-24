#pragma once

#include <dmsdk/sdk.h>
#include "bridge_helper.h"

#if defined(DM_PLATFORM_HTML5)

extern "C" {
    void js_bridge_cross_promo_getGamesList(UniversalHandler handler,
                                            dmScript::LuaCallbackInfo* success,
                                            dmScript::LuaCallbackInfo* failure);

    void js_bridge_cross_promo_show();

    void js_bridge_cross_promo_hide();

    bool js_bridge_cross_promo_isVisible();
}

#endif
