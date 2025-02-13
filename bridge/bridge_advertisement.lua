local advertisement = {}

-- Local variables
local delay_between_interstitial = 60
local interstitial_state = "failed"
local rewarded_state = "failed"

local interstitial_changed_callback = nil
local interstitial_states = { "loading", "opened", "closed", "failed"}

local rewarded_states = {"loading", "opened", "closed", "rewarded", "failed"}
local rewarded_changed_callback = nil

local get_state = function(state)
	return coroutine.wrap(function()
		for k, v in pairs(state) do
			coroutine.yield(v)
		end
	end)
end

-- Banner
function advertisement.is_banner_supported()
	return false
end

function advertisement.show_banner(options)
end

function advertisement.hide_banner()
end

function advertisement.on(event_name, callback)
	if event_name == bridge.EVENT_NAME.INTERSTITIAL_STATE_CHANGED then
		interstitial_changed_callback = callback
		
	elseif event_name == bridge.EVENT_NAME.REWARDED_STATE_CHANGED then
		rewarded_changed_callback = callback
	end
end

-- Interstitial
function advertisement.minimum_delay_between_interstitial()
	return delay_between_interstitial
end

function advertisement.set_minimum_delay_between_interstitial(delay)
	delay_between_interstitial = delay
end

function advertisement.interstitial_state()
	return interstitial_state
end

function advertisement.show_interstitial()
	if not interstitial_changed_callback then
		return
	end
	
	local getter = get_state(interstitial_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		interstitial_state = state
		interstitial_changed_callback(_, state)
	end)
end

-- Rewarded
function advertisement.rewarded_state()
	return rewarded_state
end

function advertisement.show_rewarded()
	if not rewarded_changed_callback then
		return
	end

	local getter = get_state(rewarded_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		rewarded_state = state
		rewarded_changed_callback(_, state)
	end)
end

function advertisement.check_ad_block(on_success, on_failure)
	on_success(_, false)
end

return advertisement