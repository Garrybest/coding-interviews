/*
 * 调整数组顺序使奇数位于偶数后面
 * @Author: garryfang 
 * @Date: 2019-08-30 21:17:42 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-30 21:31:36
 */
#include <functional>
#include <vector>

void Reorder(std::vector<int> &data, std::function<bool(int)> is_front)
{
    if (data.empty())
        return;
    size_t i(0), j(data.size() - 1);
    while (true)
    {
        while (i < j && is_front(data[i]))
            ++i;
        while (i < j && !is_front(data[j]))
            --j;
        if (i < j)
            std::swap(data[i], data[j]);
        else
            break;
    }
}