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

return platform