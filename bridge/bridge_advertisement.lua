local advertisement = {}

-- Local variables
local banner_state = "hidden"
local banner_changed_callback = nil
local banner_states = {"loading", "shown", "hidden", "failed"}

local delay_between_interstitial = 60
local interstitial_state = "closed"
local interstitial_changed_callback = nil
local interstitial_states = {"loading", "opened", "closed", "failed"}

local rewarded_state = "closed"
local rewarded_placement = nil
local rewarded_changed_callback = nil
local rewarded_states = {"loading", "opened", "rewarded", "closed", "failed"}

local get_state = function(state)
	return coroutine.wrap(function()
		for k, v in pairs(state) do
			coroutine.yield(v)
		end
	end)
end

-- Banner
function advertisement.is_banner_supported()
	return true
end

function advertisement.banner_state()
	return banner_state
end

function advertisement.show_banner(position, placement)
	if not banner_changed_callback then
		return
	end

	local getter = get_state(banner_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		banner_state = state
		banner_changed_callback(_, state)
	end)
end

function advertisement.hide_banner()
end

function advertisement.on(event_name, callback)
	if event_name == "banner_state_changed" then
		banner_changed_callback = callback
		
	elseif event_name == "interstitial_state_changed" then
		interstitial_changed_callback = callback
		
	elseif event_name == "rewarded_state_changed" then
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

function advertisement.show_interstitial(placement)
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

function advertisement.rewarded_placement()
	return rewarded_placement
end

function advertisement.show_rewarded(placement)
	rewarded_placement = placement
	
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