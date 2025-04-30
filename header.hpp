#ifndef HEADER
#define HEADER
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <exception>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <syncstream>
#include <chrono>

class ThreadPool {
public:
    using foo_ptr = void(*)();
    //ctor && dtor
    ThreadPool(size_t threads_count = 5);
    virtual ~ThreadPool();

    //member functions
    void push_task(foo_ptr task);
    void end_wark();

private:
    void thread_foo();

    std::mutex m_mutex;
    std::condition_variable m_cond;
    std::queue<foo_ptr> m_tasks;
    std::vector<std::thread> m_threads;
    std::vector<int> m_vec;
    std::atomic<bool> work_time;
    const size_t m_count_of_threads;
};

#endif //HEADER

