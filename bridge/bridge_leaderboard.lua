local leaderboard = {}

function leaderboard.is_supported()
	return false
end

function leaderboard.is_native_popup_supported()
	return false
end

function leaderboard.is_multiple_boards_supported()
	return false
end

function leaderboard.is_set_score_supported()
	return false
end

function leaderboard.is_get_score_supported()
	return false
end

function leaderboard.is_get_entries_supported()
	return false
end

function leaderboard.set_score(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function leaderboard.get_score(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function leaderboard.get_entries(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function leaderboard.show_native_popup(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return leaderboard