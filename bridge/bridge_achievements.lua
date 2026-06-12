local achievements = {}

function achievements.is_supported()
	return false
end

function achievements.is_get_list_supported()
	return false
end

function achievements.is_native_popup_supported()
	return false
end

function achievements.unlock(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function achievements.get_list(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function achievements.show_native_popup(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return achievements