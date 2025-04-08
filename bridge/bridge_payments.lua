local payments = {}

function payments.is_supported()
	return false
end

function payments.is_available()
	return false
end

function payments.is_get_catalog_supported()
	return false
end

function payments.is_get_purchases_supported()
	return false
end

function payments.is_consume_purchase_supported()
	return false
end

function payments.purchase(options, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function payments.consume_purchase(options, on_success, on_failure)
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