/*
 * 数组中只出现一次的两个数字
 * @Author: garryfang 
 * @Date: 2019-09-21 09:58:06 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 10:47:32
 */

#include <vector>
#include <iostream>

std::pair<int, int> findNumsAppearOnce(std::vector<int> &nums)
{
    std::pair<int, int> pair;
    if (nums.size() < 2)
        return pair;
    int nums_xor = 0;
    for (auto &&num : nums)
        nums_xor ^= num;

    if (nums_xor == 0)
        return pair;

    int idx_bit = 0;
    while ((nums_xor >> idx_bit & 1) == 0)
        ++idx_bit;

    int num1 = 0, num2 = 0;
    for (auto &&num : nums)
    {
        if ((num >> idx_bit & 1) == 0)
            num1 ^= num;
        else
            num2 ^= num;
    }
    pair.first = num1;
    pair.second = num2;
    return pair;
}
