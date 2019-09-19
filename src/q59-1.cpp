/*
 * 滑动窗口的最大值
 * @Author: garryfang 
 * @Date: 2019-09-19 21:51:20 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-19 22:10:02
 */

#include <vector>
#include <queue>

std::vector<int> maxInWin(const std::vector<int> &num, unsigned size)
{
    std::vector<int> ans;
    if (num.size() < size)
        return ans;
    std::deque<int> deque;
    for (unsigned i = 0; i < size; ++i)
    {
        while (!deque.empty() && num[i] >= num[deque.back()])
            deque.pop_back();
        deque.push_back(i);
    }
    ans.push_back(num[deque.front()]);
    for (unsigned i = size; i < num.size(); i++)
    {
        while (!deque.empty() && num[i] >= num[deque.back()])
            deque.pop_back();
        while (!deque.empty() && i - deque.front() >= size)
            deque.pop_front();
        deque.push_back(i);
        ans.push_back(num[deque.front()]);
    }
    return ans;
}