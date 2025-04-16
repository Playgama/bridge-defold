local payments = {}

function payments.is_supported()
	return false
end

function payments.purchase(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function payments.consume_purchase(id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function payments.get_catalog(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function payments.get_purchases(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return payments