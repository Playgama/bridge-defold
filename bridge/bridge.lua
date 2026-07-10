local bridge = {}
if not _bridge then
	bridge.platform = require "bridge.bridge_platform"
	bridge.cross_promo = require "bridge.bridge_cross_promo"
	bridge.remote_config = require "bridge.bridge_remote_config"
	bridge.payments = require "bridge.bridge_payments"
	bridge.achievements = require "bridge.bridge_achievements"
	bridge.tasks = require "bridge.bridge_tasks"
	bridge.daily_rewards = require "bridge.bridge_daily_rewards"
	bridge.leaderboards = require "bridge.bridge_leaderboards"
	bridge.social = require "bridge.bridge_social"
	bridge.device = require "bridge.bridge_device" 
	bridge.player = require "bridge.bridge_player"
	bridge.advertisement = require "bridge.bridge_advertisement"
	bridge.storage = require "bridge.bridge_storage"
else
	bridge = _bridge
end

-- Constants

bridge.EVENT_NAME = {
	INTERSTITIAL_STATE_CHANGED = "interstitial_state_changed",
	REWARDED_STATE_CHANGED = "rewarded_state_changed",
	BANNER_STATE_CHANGED = "banner_state_changed",
	AUDIO_STATE_CHANGED = "audio_state_changed",
	PAUSE_STATE_CHANGED = "pause_state_changed",
	ADVANCED_BANNERS_STATE_CHANGED = "advanced_banners_state_changed",
	PLATFORM_STORAGE_AVAILABILITY_CHANGED = "platform_storage_availability_changed"
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
	REWARDED = "rewarded",
	CLOSED = "closed",
	FAILED = "failed",
}

bridge.BANNER_STATE = {
	LOADING = "loading",
	SHOWN = "shown",
	HIDDEN = "hidden",
	FAILED = "failed",
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
	LEVEL_STARTED = "level_started",
	LEVEL_PAUSED = "level_paused",
	LEVEL_RESUMED = "level_resumed",
	LEVEL_COMPLETED = "level_completed",
	LEVEL_FAILED = "level_failed",
}

bridge.LEADERBOARD_TYPE = {
	NOT_AVAILABLE = "not_available",
	IN_GAME = "in_game",
	NATIVE = "native",
	NATIVE_POPUP = "native_popup",
}

return bridge