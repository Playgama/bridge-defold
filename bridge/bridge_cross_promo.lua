local cross_promo = {}

-- Local variables
local is_visible = false

function cross_promo.get_games_list(on_success, on_failure)
	if on_success then
		on_success(nil, {})
	end
end

function cross_promo.show()
	is_visible = true
end

function cross_promo.hide()
	is_visible = false
end

function cross_promo.is_visible()
	return is_visible
end

return cross_promo
