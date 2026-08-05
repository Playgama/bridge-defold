local notifications = {}

function notifications.is_supported()
	return false
end

function notifications.schedule(notification, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function notifications.cancel(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function notifications.cancel_all(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return notifications
