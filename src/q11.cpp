/*
 * 旋转数组的最小数字
 * @Author: garryfang 
 * @Date: 2019-09-02 11:07:56 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 12:08:15
 */
#include <vector>
#include <stdexcept>

int min(std::vector<int> &nums)
{
    if (nums.empty())
        throw std::invalid_argument("Invalid input.");

    std::vector<int>::size_type low(0), high(nums.size() - 1);
    while (low < high)
    {
        std::vector<int>::size_type mid((low + high) / 2);
        if (nums[mid] < nums[high])
            high = mid;
        else if (nums[mid] > nums[high])
            low = mid + 1;
        else
        {
            if (nums[mid] > nums[low])
                return nums[low];
            else if (nums[mid] < nums[low])
                high = mid;
            else
                --high;
        }
    }
    return nums[low];
}