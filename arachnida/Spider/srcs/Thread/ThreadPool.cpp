#include "Thread.hpp"
#include "Parser.hpp"

ThreadPool::ThreadPool(size_t threadCount) : _stop(false)
{
    for (size_t i = 0; i < threadCount; i++)
        _workers.emplace_back(&ThreadPool::worker, this);
}

ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _stop = true;
    }

    _condition.notify_all();

    for (std::thread& worker : _workers)
    {
        if (worker.joinable())
            worker.join();
    }
}
