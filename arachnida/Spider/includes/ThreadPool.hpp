#pragma once

#include <thread>
#include <mutex>
#include <atomic>
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

class ThreadPool {
	private:
		// Threads
		std::vector<std::thread> _workers;

		// Shared task queue
		std::deque<Task> _tasks;
		std::deque<Task> _tasksBuffer;

		std::unordered_set<std::string> _visited;

		// Synchronization
		std::mutex _mutex;
		std::condition_variable _condition;

		// State
		std::atomic<bool> _stop;
		std::atomic<uint8_t> _nbThreadRunning;
		std::atomic<uint8_t> _depth;

	public:
		ThreadPool(std::size_t threadCount, std::deque<Task> tasks);
		~ThreadPool();

		void worker();
};
