local leaderboards = {}

function leaderboards.type()
	return "not_available"
end

function leaderboards.set_score(id, score, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function leaderboards.get_entries(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function leaderboards.show_native_popup(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return leaderboards