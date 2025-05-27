local advertisement = {}

-- Local variables
local banner_state = "hidden"
local banner_changed_callback = nil
local simulate_banner_states = {"loading", "shown"}

local delay_between_interstitial = 60
local interstitial_state = "closed"
local interstitial_changed_callback = nil
local simulate_interstitial_states = {"loading", "opened", "closed"}

local rewarded_state = "closed"
local rewarded_placement = nil
local rewarded_changed_callback = nil
local simulate_rewarded_states = {"loading", "opened", "rewarded", "closed"}

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
	local getter = get_state(simulate_banner_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		
		banner_state = state
		if banner_changed_callback then
			banner_changed_callback(_, banner_state)
		end
	end)
end

function advertisement.hide_banner()
	banner_state = "hidden"
	if banner_changed_callback then
		banner_changed_callback(_, banner_state)
	end
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
	local getter = get_state(simulate_interstitial_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		
		interstitial_state = state
		if interstitial_changed_callback then
			interstitial_changed_callback(_, interstitial_state)
		end
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

	local getter = get_state(simulate_rewarded_states)
	timer.delay(0.1, true, function(_, handle)
		local state = getter()
		if not state then
			timer.cancel(handle)
			return
		end
		
		rewarded_state = state
		if rewarded_changed_callback then
			rewarded_changed_callback(_, rewarded_state)
		end
	end)
end

function advertisement.check_ad_block(on_success, on_failure)
	on_success(_, false)
end

return advertisement