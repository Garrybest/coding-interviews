/*
 * 包含min函数的栈
 * @Author: garryfang 
 * @Date: 2019-09-04 11:05:45 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 11:23:16
 */

#include <stack>
#include <stdexcept>

template <typename T>
class StackWithMin
{
private:
    std::stack<T> _data;
    std::stack<T> _min;

public:
    StackWithMin() {}
    ~StackWithMin() {}
    void push(const T &value);
    void pop();
    const T &top();
    const T &min();
    unsigned int size();
};

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    _data.push(value);
    if (_min.empty() || _min.top() > value)
        _min.push(value);
    else
        _min.push(_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
    if (_data.empty())
        throw std::runtime_error("No element in stack.");
    _data.pop();
    _min.pop();
}

template <typename T>
const T &StackWithMin<T>::top()
{
    if (_data.empty())
        throw std::runtime_error("No element in stack.");
    return _data.top();
}

template <typename T>
const T &StackWithMin<T>::min()
{
    if (_min.empty())
        throw std::runtime_error("No element in stack.");
    return _min.top();
}

template <typename T>
unsigned int StackWithMin<T>::size()
{
    return _data.size();
}
