/*
 * 打印从1到最大的n位数
 * @Author: garryfang 
 * @Date: 2019-09-26 15:42:35 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 16:16:05
 */

#include <vector>
#include <iostream>

void print(std::vector<char> &nums)
{
    auto iter = nums.begin();
    while (iter != nums.end() && *iter == '0')
        ++iter;
    if (iter == nums.end())
        return;
    while (iter != nums.end())
        std::cout << *iter++;
    std::cout << " ";
}

void printToMaxOfNDigitsCore(unsigned idx, std::vector<char> &nums)
{
    if (idx == nums.size()) {
        print(nums);
        return;
    }
    for (unsigned i = 0; i < 10; ++i)
    {
        printToMaxOfNDigitsCore(idx + 1, nums);
        ++nums[idx];
    }
    nums[idx] = '0';     
}

void printToMaxOfNDigits(unsigned n)
{
    if (n == 0)
        return;
    std::vector<char> nums(n, '0');
    printToMaxOfNDigitsCore(0, nums);
}
