local social = {}

-- Share
function social.is_share_supported()
	return false
end

function social.share(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Join Community
function social.is_join_community_supported()
	return false
end

function social.join_community(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Invite Friends
function social.is_invite_friends_supported()
	return false
end

function social.invite_friends(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Create Post
function social.is_create_post_supported()
	return false
end

function social.create_post(options, payload, on_success, on_failure)
	if type(payload) == "function" then
		on_failure = on_success
		on_success = payload
	end
	if on_failure then
		on_failure()
	end
end

-- Add to Favorites
function social.is_add_to_favorites_supported()
	return false
end

function social.add_to_favorites(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Add to Home Screen
function social.is_add_to_home_screen_supported()
	return false
end

function social.add_to_home_screen(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Rate Game
function social.is_rate_supported()
	return false
end

function social.rate(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

-- Post Reward
function social.is_post_reward_supported()
	return false
end

function social.get_post_reward(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return social