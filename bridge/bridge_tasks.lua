local tasks = {}

function tasks.get_tasks(on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function tasks.add_progress(metric, amount, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

function tasks.claim_reward(task_id, on_success, on_failure)
	if on_failure then
		on_failure()
	end
end

return tasks
