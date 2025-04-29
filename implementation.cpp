#include "header.hpp"


ThreadPool::ThreadPool(size_t threads_count) : work_time(true), m_count_of_threads{threads_count}{
    for (int i = 0; i <  threads_count; ++i) {
        m_threads.emplace_back(&ThreadPool::thread_foo, this);
    }
}

ThreadPool::~ThreadPool(){
     {
        std::lock_guard<std::mutex> lock(m_mutex);
        work_time = false;
     }
    m_cond.notify_all();
    for (int i = 0; i < m_count_of_threads; ++i) {
        if (m_threads[i].joinable()) {
            m_threads[i].join();
        }
    }
}

void ThreadPool::thread_foo() {
    std::unique_lock<std::mutex> lock(m_mutex, std::defer_lock);
    while (true) {
        lock.lock();
        m_cond.wait(lock, [this]() { return !m_tasks.empty() || !work_time; });
        if (!work_time && m_tasks.empty()) {
            break;
        }
        if (!m_tasks.empty()){
            foo_ptr fptr = m_tasks.front();
            m_tasks.pop();
            lock.unlock();
            fptr();
        }  
    }
    return;
}

void ThreadPool::push_task(foo_ptr task) {
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_tasks.push(task);
    }
    m_cond.notify_one();
    return;
}

void ThreadPool::end_wark() {
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        work_time = false;
    }
    m_cond.notify_all();
    return;
}

























