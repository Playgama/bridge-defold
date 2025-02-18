local bridge = {}
if not _bridge then
	bridge.game = require "bridge.bridge_game"
	bridge.platform = require "bridge.bridge_platfrom"
	bridge.remote_config = require "bridge.bridge_remote_config"
	bridge.payments = require "bridge.bridge_payments"
	bridge.achievements = require "bridge.bridge_achievements"
	bridge.leaderboard = require "bridge.bridge_leaderboard"
	bridge.social = require "bridge.bridge_social"
	bridge.device = require "bridge.bridge_device" 
	bridge.player = require "bridge.bridge_player"
	bridge.advertisement = require "bridge.bridge_advertisement"
	bridge.storage = require "bridge.bridge_storage"
else
	bridge = _bridge
end

-- Constants

bridge.PLATFORM_ID = {
	VK = "vk",
	OK = "ok",
	YANDEX = "yandex",
	CRAZY_GAMES = "crazy_games",
	ABSOLUTE_GAMES = "absolute_games",
	GAME_DISTRIBUTION = "game_distribution",
	PLAYGAMA = "playgama",
	WORTAL = "wortal",
	PLAYDECK = "playdeck",
	TELEGRAM = "telegram",
	Y8 = "y8",
	LAGGED = "lagged",
	FACEBOOK = "facebook",
	POKI = "poki",
	MOCK = "mock",
	QA_TOOL = "qa_tool",
}


bridge.EVENT_NAME = {
	INTERSTITIAL_STATE_CHANGED = "interstitial_state_changed",
	REWARDED_STATE_CHANGED = "rewarded_state_changed",
	BANNER_STATE_CHANGED = "banner_state_changed",
	VISIBILITY_STATE_CHANGED = "visibility_state_changed",
}


bridge.VISIBILITY_STATE = {
	VISIBLE = "visible",
	HIDDEN = "hidden",
}


bridge.INTERSTITIAL_STATE = {
	LOADING = "loading",
	OPENED = "opened",
	CLOSED = "closed",
	FAILED = "failed",
}


bridge.REWARDED_STATE = {
	LOADING = "loading",
	OPENED = "opened",
	CLOSED = "closed",
	FAILED = "failed",
	REWARDED = "rewarded",
}


bridge.BANNER_STATE = {
	LOADING = "loading",
	SHOWN = "shown",
	HIDDEN = "hidden",
	FAILED = "failed",
}

bridge.STORAGE_TYPE = {
	LOCAL_STORAGE = "local_storage",
	PLATFORM_INTERNAL = "platform_internal",
}


bridge.DEVICE_TYPE = {
	DESKTOP = "desktop",
	MOBILE = "mobile",
	TABLET = "tablet",
	TV = "tv",
}

bridge.PLATFORM_MESSAGE = {
	GAME_READY = "game_ready",
	IN_GAME_LOADING_STARTED = "in_game_loading_started",
	IN_GAME_LOADING_STOPPED = "in_game_loading_stopped",
	GAMEPLAY_STARTED = "gameplay_started",
	GAMEPLAY_STOPPED = "gameplay_stopped",
	PLAYER_GOT_ACHIEVEMENT = "player_got_achievement",
	GAME_OVER = "game_over",
}

bridge.ACTION_NAME = {
	INITIALIZE = "initialize",
	AUTHORIZE_PLAYER = "authorize_player",
	SHARE = "share",
	INVITE_FRIENDS = "invite_friends",
	JOIN_COMMUNITY = "join_community",
	CREATE_POST = "create_post",
	ADD_TO_HOME_SCREEN = "add_to_home_screen",
	ADD_TO_FAVORITES = "add_to_favorites",
	RATE = "rate",
	SET_LEADERBOARD_SCORE = "set_leaderboard_score",
	GET_LEADERBOARD_SCORE = "get_leaderboard_score",
	GET_LEADERBOARD_ENTRIES = "get_leaderboard_entries",
	GET_PURCHASES = "get_purchases",
	GET_CATALOG = "get_catalog",
	PURCHASE = "purchase",
	CONSUME_PURCHASE = "consume_purchase",
	GET_REMOTE_CONFIG = "get_remote_config",
	GET_STORAGE_DATA = "get_storage_data",
	SHOW_LEADERBOARD_NATIVE_POPUP = "show_leaderboard_native_popup",
	CLIPBOARD_WRITE = "clipboard_write",
	ADBLOCK_DETECT = "adblock_detect",
}


return bridge