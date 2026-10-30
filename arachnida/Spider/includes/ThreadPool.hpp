#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <deque>
#include <string>
#include <cstdint>

struct Task
{
    std::string url;
    uint8_t depth;
    bool isImage;
};

ThreadPool {
	private:
		// Threads
		std::vector<std::thread> _workers;

		// Shared task queue
		std::deque<Task> _tasks;
		std::deque<Task> _tasksBuffer;

		// Synchronization
		std::mutex _mutex;
		std::condition_variable _condition;

		// State
		bool _stop;

	public:
		ThreadPool(std::size_t threadCount, std::deque<Task> tasks);
		~ThreadPool();

		void worker();
};
