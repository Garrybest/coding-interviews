/*
 * 和为s的数字
 * @Author: garryfang 
 * @Date: 2019-09-20 18:05:44 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-20 19:42:59
 */

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::pair<int, int>> findNumbersWithSum(std::vector<int> &numbers, int sum)
{
    std::vector<std::pair<int, int>> ans;
    if (numbers.size() < 2)
        return ans;
    std::sort(numbers.begin(), numbers.end());
    auto l = numbers.begin(), r = numbers.end() - 1;
    while (l < r)
    {
        int lv = *l, rv = *r;
        if (lv + rv < sum)
            ++l;
        else if (lv + rv > sum)
            --r;
        else
        {
            ans.emplace_back(lv, rv);
            while (l != numbers.end() && *l == lv)
                ++l;
            while (r != numbers.begin() - 1 && *r == rv)
                --r;
        }
    }
    return ans;
}
