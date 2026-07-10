local daily_rewards = {}

function daily_rewards.get_rewards(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function daily_rewards.get_current_day(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function daily_rewards.get_current_reward(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function daily_rewards.claim_current_reward(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return daily_rewards
