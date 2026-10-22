local multiplayer = {}

function multiplayer.on(event_name, callback)

end

function multiplayer.is_supported()
	return false
end

function multiplayer.state()
	return "disconnected"
end

function multiplayer.is_in_room()
	return false
end

function multiplayer.is_host()
	return false
end

function multiplayer.player_id()
	return nil
end

function multiplayer.host_id()
	return nil
end

function multiplayer.room_id()
	return nil
end

function multiplayer.room()
	return nil
end

function multiplayer.players()
	return {}
end

function multiplayer.is_invite_supported()
	return false
end

function multiplayer.launch_room_id()
	return nil
end

function multiplayer.create_room(options, on_success, on_failure)
	if type(options) == "function" then
		on_failure = on_success
		on_success = options
	end
	if on_failure then
		on_failure()
	end
end

function multiplayer.join_room(room_id, options, on_success, on_failure)
	if type(options) == "function" then
		on_failure = on_success
		on_success = options
	end
	if on_failure then
		on_failure()
	end
end

function multiplayer.join_or_create_room(options, on_success, on_failure)
	if type(options) == "function" then
		on_failure = on_success
		on_success = options
	end
	if on_failure then
		on_failure()
	end
end

function multiplayer.get_rooms(options, on_success, on_failure)
	if type(options) == "function" then
		on_failure = on_success
		on_success = options
	end
	if on_failure then
		on_failure()
	end
end

function multiplayer.invite_to_room(options, on_success, on_failure)
	if type(options) == "function" then
		on_failure = on_success
		on_success = options
	end
	if on_failure then
		on_failure()
	end
end

function multiplayer.leave_room()

end

function multiplayer.set_room_open(is_open)

end

function multiplayer.set_room_visible(is_visible)

end

function multiplayer.set_room_properties(properties)

end

function multiplayer.set_player_properties(properties)

end

function multiplayer.send(message_type, data, options)

end

return multiplayer
