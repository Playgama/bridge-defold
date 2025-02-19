local device = {}

-- Local variables
local sysinfo = sys.get_sys_info()

function device.type()
	return "desktop"
end

return device