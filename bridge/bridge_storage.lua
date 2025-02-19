local storage = {}

-- Local variables
local app_name = sys.get_config_string("title", "defold_game")
local path_to_save_file = sys.get_save_file(app_name, "bridge_storage_data")
local load_data = {}

function storage.default_type()
	return "local_storage"
end

function storage.is_supported(storageType)
	if storageType == "local_storage" then
		return true
	elseif storageType == "platform_internal" then
		return false
	end
end

function storage.is_available(storageType)
	if storageType == "local_storage" then
		return true
	elseif storageType == "platform_internal" then
		return false
	end
end

function storage.get(table_keys, on_success, on_failure, storageType)
	load_data = sys.load(path_to_save_file)

	local game_data = {}

	for k, v in pairs(data_table) do
		if load_data[v] then
			game_data[v] = load_data[v]
		end
	end
	if on_success then
		on_success(_, game_data)
	end
	
end

function storage.set(table_data, on_success, on_failure, storageType)
	for k, v in pairs(data_table) do
		if not load_data[k] then
			load_data[k] = v
		end
	end
	sys.save(path_to_save_file, load_data)
	
	if on_success then
		on_success()
	end
end

function storage.delete(table_keys, on_success, on_failure, storageType)
	for k, v in pairs(data_table) do
		if load_data[v] then
			load_data[v] = nil
		end
	end
	sys.save(path_to_save_file, load_data)
	
	if on_success then
		on_success()
	end
end

return storage