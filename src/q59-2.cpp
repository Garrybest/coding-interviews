/*
 * 队列的最大值
 * @Author: garryfang 
 * @Date: 2019-09-20 10:02:54 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-20 12:47:08
 */

#include <deque>
#include <stdexcept>

template <typename T>
class QueueWithMax
{
public:
    QueueWithMax() {}

    void push(T value)
    {
        for (auto iter = max_queue.rbegin(); iter != max_queue.rend() && *iter < value; ++iter)
            *iter = value;
        max_queue.push_back(value);
        queue.push_back(value);
    }

    void pop()
    {
        if (queue.empty())
            throw std::runtime_error("Empty queue.");
        max_queue.pop_front();
        queue.pop_front();
    }

    T &max()
    {
        if (queue.empty())
            throw std::runtime_error("Emtpy queue.");
        return max_queue.front();
    }

private:
    std::deque<T> queue;
    std::deque<T> max_queue;
};
