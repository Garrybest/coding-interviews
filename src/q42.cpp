/*
 * 连续子数组的最大和
 * @Author: garryfang 
 * @Date: 2019-09-26 10:59:25 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 11:03:39
 */

#include <vector>

int maxSum(std::vector<int> &nums)
{
    int ans = 0, sum = 0;
    for (auto &&num : nums)
    {
        sum = sum > 0 ? sum + num : num;
        ans = std::max(ans, sum);
    }
    return ans;
}