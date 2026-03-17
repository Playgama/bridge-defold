local storage = {}

-- Local variables
local app_name = sys.get_config_string("project.title", "defold_game")
local path_to_save_file = sys.get_save_file(app_name, "bridge_storage_data")
local load_data = {}

function storage.default_type()
	return "local_storage"
end

function storage.is_supported(storage_type)
	if storage_type == "local_storage" then
		return true
	elseif storage_type == "platform_internal" then
		return false
	end
end

function storage.is_available(storage_type)
	if storage_type == "local_storage" then
		return true
	elseif storage_type == "platform_internal" then
		return false
	end
end

function storage.get(table_keys, on_success, on_failure, storage_type)
	load_data = sys.load(path_to_save_file) or {}

	local game_data = {}

	for _, key in ipairs(table_keys) do
		if load_data[key] ~= nil then
			game_data[key] = load_data[key]
		end
	end
	if on_success then
		on_success(nil, game_data)
	end
end

function storage.set(table_data, on_success, on_failure, storage_type)
	load_data = sys.load(path_to_save_file) or {}

	for k, v in pairs(table_data) do
		load_data[k] = v
	end
	sys.save(path_to_save_file, load_data)
	if on_success then
		on_success()
	end
end

function storage.delete(table_keys, on_success, on_failure, storage_type)
	load_data = sys.load(path_to_save_file) or {}

	for _, key in ipairs(table_keys) do
		if load_data[key] ~= nil then
			load_data[key] = nil
		end
	end
	sys.save(path_to_save_file, load_data)
	if on_success then
		on_success()
	end
end

return storage