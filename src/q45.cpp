/*
 * 把数组排成最小的数
 * @Author: garryfang 
 * @Date: 2019-09-24 17:19:35 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-24 20:38:31
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void printMinNum(std::vector<int> &nums)
{
    if (nums.empty())
        return;
    std::vector<std::string> nums_str;
    nums_str.reserve(nums.size());
    for (auto &&num : nums)
        nums_str.push_back(std::to_string(num));

    std::sort(nums_str.begin(), nums_str.end(), [](const std::string &s1, const std::string &s2) {
        return s1 + s2 < s2 + s1;
    });

    for (auto &s : nums_str)
        std::cout << s;
}
