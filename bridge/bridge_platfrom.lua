local platform = {}

-- Local variables
local sysinfo = sys.get_sys_info()

function platform.language()
	return sysinfo.device_language
end

function platform.id()
	return "mock"
end

function platform.payload()
	return nil
end

function platform.tld()
	return nil
end

function platform.send_message(message, on_success, on_failure)
	if on_success then
		on_success()
	end
end

function platform.get_server_time(on_success, on_failure)
	on_success(nil, os.time())
end

function platform.is_get_all_games_supported()
	return false
end

function platform.get_all_games(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function platform.is_get_game_by_id_supported()
	return false
end

function platform.get_game_by_id(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return platform