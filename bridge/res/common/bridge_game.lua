local game = {}

function game.visibility_state()
	return "visable"
end

function game.on()
	window.set_listener(function(self, state)
		if state == window.WINDOW_EVENT_FOCUS_LOST then
			return "hidden"
		elseif state == window.WINDOW_EVENT_FOCUS_GAINED then
			return "visable"
		end
	end)
	
end



return game