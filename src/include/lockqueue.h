#pragma once
#include <queue>
#include <thread>
#include <mutex> //pthread_mutex_t     线程互斥操作
#include <condition_variable> //pthread_condition_t  线程间通信

//异步写日志的日志队列
template<typename T>           //模板代码只能写在头文件中了
class LockQueue
{
public:
    void Push(const T &data)    //线程安全的入队和出队    //工作线程调用 多个worker线程都会写日志queue
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_condvariable.notify_one();
    }

    //一个线程读日志queue，写日志文件
    T Pop()                                 //往磁盘写日志线程调用
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty())
        {
            //日志队列为空，线程进入wait状态(并把持有的锁释放了)
            m_condvariable.wait(lock);
        }
        T data = m_queue.front();
        m_queue.pop();
        return data;
    }

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};