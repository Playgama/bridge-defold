local player = {}

function player.is_authorization_supported()
	return false
end

function player.is_authorized()
	return false
end

function player.id()
	return nil
end

function player.name()
	return nil
end

function player.photos()
	return {}
end

function player.authorize(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return player