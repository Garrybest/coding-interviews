/*
 * 数组中唯一只出现一次的数字，其他数字都出现了三次
 * @Author: garryfang 
 * @Date: 2019-09-21 10:48:19 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 11:12:54
 */

#include <vector>
#include <stdexcept>
#include <iostream>

int findNumberAppearingOnce(std::vector<int> &nums)
{
    if (nums.empty())
        throw std::invalid_argument("Empty input.");

    int size = sizeof(int) * 8;
    int times[size] = {0};

    for (auto &&num : nums)
    {
        for (int i = 0; i < size; ++i)
        {
            if ((num >> i & 1) == 1)
                ++times[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < size; ++i)
    {
        int bit = times[i] % 3;
        if (bit == 2)
            throw std::invalid_argument("Invalid input.");
        else if (bit == 1)
            ans |= 1 << i;
    }
    return ans;
}
