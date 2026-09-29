let js_bridge_social = {
    // #region Share
    js_bridge_social_isShareSupported: function () {
        return bridge.social.isShareSupported;
    },

    js_bridge_social_share: function (handler, id, onSuccess, onFailure) {
        bridge.social.share(UTF8ToString(id) || undefined)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Join Community
    js_bridge_social_isJoinCommunitySupported: function () {
        return bridge.social.isJoinCommunitySupported;
    },

    js_bridge_social_joinCommunity: function (handler, onSuccess, onFailure) {
        bridge.social.joinCommunity()
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Invite Friends
    js_bridge_social_isInviteFriendsSupported: function () {
        return bridge.social.isInviteFriendsSupported;
    },

    js_bridge_social_inviteFriends: function (handler, id, onSuccess, onFailure) {
        bridge.social.inviteFriends(UTF8ToString(id) || undefined)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Create Post
    js_bridge_social_isCreatePostSupported: function () {
        return bridge.social.isCreatePostSupported;
    },

    js_bridge_social_createPost: function (handler, id, payload, onSuccess, onFailure) {
        var jsPayload = payload ? UTF8ToString(payload) : undefined;
        bridge.social.createPost(UTF8ToString(id) || undefined, jsPayload)
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Add to Favorites
    js_bridge_social_isAddToFavoritesSupported: function () {
        return bridge.social.isAddToFavoritesSupported;
    },

    js_bridge_social_addToFavorites: function (handler, onSuccess, onFailure) {
        bridge.social.addToFavorites()
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },    
    // #endregion

    // #region Add to Home Screen
    js_bridge_social_isAddToHomeScreenSupported: function () {
        return bridge.social.isAddToHomeScreenSupported;
    },

    js_bridge_social_addToHomeScreen: function (handler, onSuccess, onFailure) {
        bridge.social.addToHomeScreen()
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Rate Game
    js_bridge_social_isRateSupported: function () {
        return bridge.social.isRateSupported;
    },

    js_bridge_social_rate: function (handler, onSuccess, onFailure) {
        bridge.social.rate()
            .then(() => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson());
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion

    // #region Post Reward
    js_bridge_social_isPostRewardSupported: function () {
        return bridge.social.isPostRewardSupported;
    },

    js_bridge_social_getPostReward: function (handler, onSuccess, onFailure) {
        bridge.social.getPostReward()
            .then(rewards => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 0, packToJson(rewards));
            })
            .catch(error => {
                {{{ makeDynCall('viiii', 'handler') }}} (onSuccess, onFailure, 1, packToJson(error));
            })
    },
    // #endregion
}

mergeInto(LibraryManager.library, js_bridge_social);