/*
 * 数组中的逆序对
 * @Author: garryfang 
 * @Date: 2019-09-21 20:06:58 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 20:45:19
 */

#include <vector>
#include <iostream>

void merge(std::vector<int> &nums, std::vector<int> &aux, unsigned l, unsigned m, unsigned r, std::vector<std::pair<int, int>> &pairs)
{
    for (unsigned i = l; i <= r; ++i)
        aux[i] = nums[i];
    unsigned i1 = l, i2 = m + 1, idx = l;
    while (idx <= r)
    {
        if (i1 > m)
            nums[idx++] = aux[i2++];
        else if (i2 > r)
        {
            for (unsigned i = m + 1; i <= r; ++i)
                pairs.push_back({aux[i1], aux[i]});
            nums[idx++] = aux[i1++];
        }
        else if (aux[i1] <= aux[i2])
        {
            for (unsigned i = m + 1; i < i2; ++i)
                pairs.push_back({aux[i1], aux[i]});
            nums[idx++] = aux[i1++];
        }
        else
            nums[idx++] = aux[i2++];
    }
}

void sort(std::vector<int> &nums, std::vector<int> &aux, unsigned l, unsigned r, std::vector<std::pair<int, int>> &pairs)
{
    if (l >= r)
        return;
    unsigned m = (l + r) / 2;
    sort(nums, aux, l, m, pairs);
    sort(nums, aux, m + 1, r, pairs);
    merge(nums, aux, l, m, r, pairs);
}

std::vector<std::pair<int, int>> inversePair(std::vector<int> &nums)
{
    std::vector<std::pair<int, int>> pairs;
    if (nums.size() < 2)
        return pairs;
    std::vector<int> aux(nums.size());
    sort(nums, aux, 0, nums.size() - 1, pairs);
    return pairs;
}
