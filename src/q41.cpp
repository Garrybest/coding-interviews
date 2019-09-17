/*
 * 数据流中的中位数
 * @Author: garryfang 
 * @Date: 2019-09-09 10:51:59 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-09 11:25:08
 */

#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>

template <typename T>
class DynamicArray
{
private:
    std::priority_queue<T> max;
    std::priority_queue<T, std::vector<T>, std::greater<T>> min;

public:
    DynamicArray() {}
    ~DynamicArray() {}
    void insert(T val)
    {
        if (max.size() > min.size())
        {
            if (val < max.top())
            {
                min.push(max.top());
                max.pop();
                max.push(val);
            }
            else
            {
                min.push(val);
            }
        }
        else
        {
            max.push(val);
        }
    }

    T getMedian()
    {
        if (max.empty())
            throw std::runtime_error("Empty heap.");

        T median = max.top();
        max.pop();
        if (max.size() == min.size())
        {
            median = (median + min.top()) / 2;
            min.pop();
        }
        return median;
    }
};
