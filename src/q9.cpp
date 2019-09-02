/*
 * @Author: garryfang 
 * @Date: 2019-09-02 10:03:49 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 10:25:32
 */
#include <stack>
#include <stdexcept>

template <typename T>
class Queue
{
public:
    Queue(void) {}
    ~Queue(void) {}

    void enqueue(const T &node);
    T dequeue();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template <typename T>
void Queue<T>::enqueue(const T &node)
{
    stack1.push(node);
}

template <typename T>
T Queue<T>::dequeue()
{
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(std::move(stack1.top()));
            stack2.pop();
        }
    }
    if (stack2.empty())
        throw std::runtime_error("Queue is empty.");

    T &top = stack2.top();
    stack2.pop();
    return top;
}