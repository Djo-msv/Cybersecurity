#include "ThreadPool.hpp"

#include <iostream>

ThreadPool::ThreadPool(size_t threadCount, std::deque<Task> tasks) : _stop(false), _nbThreadRunning(0), _tasks(tasks), _depth(tasks.depth)
{
	std::cout << "Thread count : " << threadCount << std::endl << std::endl; 
    for (size_t i = 0; i < threadCount; i++)
        _workers.emplace_back(&ThreadPool::worker, this);
}

ThreadPool::~ThreadPool()
{
    {
        _stop.store(true, std::memory_order_release);
    }

    _condition.notify_all();

    for (std::thread& worker : _workers)
    {
        if (worker.joinable())
            worker.join();
    }
}
