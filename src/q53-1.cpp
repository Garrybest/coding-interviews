/*
 * 数字在排序数组中出现的次数
 * @Author: garryfang 
 * @Date: 2019-09-21 15:50:58 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 16:21:58
 */

#include <vector>
#include <stdexcept>

int getNumberOfKBegin(std::vector<int> &nums, int k)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (nums[m] < k)
            l = m + 1;
        else if (nums[m] > k)
            r = m - 1;
        else
            r = m;
    }
    return nums[l] == k ? l : -1;
}

int getNumberOfKEnd(std::vector<int> &nums, int k)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (nums[m] < k)
            l = m + 1;
        else if (nums[m] > k)
            r = m - 1;
        else
            l = m;
    }
    return nums[r] == k ? r : -1;
}

int getNumberOfK(std::vector<int> &nums, int k)
{
    if (nums.empty())
        return -1;
    int left = getNumberOfKBegin(nums, k), right = getNumberOfKEnd(nums, k);
    if (left == -1 || right == -1)
        throw std::invalid_argument("K does not exist in nums.");
    return right - left + 1;
}
