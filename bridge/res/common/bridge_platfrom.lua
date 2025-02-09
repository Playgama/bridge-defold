local platform = {}

function platform.language()
	return "en"
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

function platform.send_message(msg, callback)
	callback()
end

function platform.get_server_time(callback)
	callback(nil, os.clock()) -- TODO to get state lua
end

return platform