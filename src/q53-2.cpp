/*
 * 0 ~ n-1中缺失的数字
 * @Author: garryfang 
 * @Date: 2019-09-21 18:36:23 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 18:40:12
 */

#include <vector>

int getMissingNum(std::vector<int> &nums)
{
    int ans = nums.size();
    for (unsigned i = 0; i < nums.size(); ++i)
    {
        ans ^= i;
        ans ^= nums[i];
    }
    return ans;
}
