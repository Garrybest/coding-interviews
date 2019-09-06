/*
 * 最小的k个数（适合处理海量数据）
 * @Author: garryfang 
 * @Date: 2019-09-06 09:52:40 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-06 10:32:09
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

void push(std::priority_queue<int> &pq, unsigned k, int value)
{
    if (pq.size() == k)
    {
        if (pq.top() > value)
        {
            pq.pop();
            pq.push(value);
        }
    }
    else
    {
        pq.push(value);
    }
}

std::priority_queue<int> getLeastNumbersByPq(std::vector<int> &numbers, unsigned k)
{
    std::priority_queue<int> pq;
    for (auto &&num : numbers)
        push(pq, k, num);
    return std::move(pq);
}
