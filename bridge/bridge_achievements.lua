local achievements = {}

function achievements.unlock(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function achievements.get_achievements(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return achievements