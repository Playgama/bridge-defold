local remote_config = {}

function remote_config.is_supported()
	return false
end

function remote_config.set_dynamic_parameters(parameters)
end

function remote_config.get(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return remote_config