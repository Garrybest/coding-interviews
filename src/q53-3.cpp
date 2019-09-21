/*
 * 数组中数值和下标相等的元素
 * @Author: garryfang 
 * @Date: 2019-09-21 18:43:59 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 18:47:54
 */

#include <vector>

int getNumberSameAsIdx(std::vector<int> &nums)
{
    if (nums.empty())
        return -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] > m)
            r = m - 1;
        else if (nums[m] < m)
            l = m + 1;
        else
            return m;
    }
    return -1;
}