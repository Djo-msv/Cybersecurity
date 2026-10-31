#include "ThreadPool.hpp"

Task ThreadPool::getTask() {
	std::unique_lock<std::mutex> lock(_mutex);
	 
	_condition.wait(lock, [this] {
		return _stop || !_tasks.empty();
	});

	if (_stop.load(std::memory_order_acquire)) {
		return (NULL);
	if (_tasks.empty() && _activeWorkers == 0) {
		if (_depth == 0) {
			_stop.store(true, std::memory_order_release);
			return (NULL);
		}
		_depth--;
		std::swap(_tasks, _tasksBuffer);
		_condition.notify_all();
	 }

	Task task = _tasks.front();
	_tasks.pop_front();

	if (visited.find(task.url)) {
		lock.unlock();
		return (NULL);
	}
	visited.insert(task.url);
	lock.unlock();
	_nbThreadRunning++;
	return (task);
}

void ThreadPool::worker() {
	CURL *curl;
    CURLcode res;
	Task task;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
	while (true) {
		if (_stop.load(std::memory_order_acquire)) {
			curl_global_cleanup();
			return ;
		}
		if (!(task = getTask()))
			continue ;
		// do Stuff
		_nbThreadRunning--;
	}
}
