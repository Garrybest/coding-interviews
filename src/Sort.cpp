/*
 * 排序相关算法
 * @Author: garryfang 
 * @Date: 2019-09-06 21:02:54 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-06 22:04:53
 */

#include <iostream>
#include <vector>

namespace sort
{

std::vector<int> array{1, 7, 2, 9, 5, 4};
std::vector<int> aux(6);

/*
 * 选择排序
 */
void bubbleSort(std::vector<int> &nums, unsigned low, unsigned high)
{
    for (unsigned i = high; i > low; --i)
    {
        for (unsigned j = low; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
                std::swap(nums[j], nums[j + 1]);
        }
    }
}

/*
 * 选择排序
 */
void selectSort(std::vector<int> &nums, unsigned low, unsigned high)
{
    for (unsigned i = low; i <= high; ++i)
    {
        int min = i;
        for (unsigned j = i + 1; j <= high; ++j)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        std::swap(nums[i], nums[min]);
    }
}

/*
 * 插入排序
 */
void insertSort(std::vector<int> &nums, unsigned low, unsigned high)
{
    for (unsigned i = low; i <= high; ++i)
    {
        int num = nums[low];
        unsigned j = i;
        for (; j > low && nums[j - 1] > num; --j)
            nums[j] = nums[j - 1];
        nums[j] = num;
    }
}

/*
 * 快速排序
 */
unsigned partition(std::vector<int> &nums, unsigned low, unsigned high)
{
    if (low == high)
        return low;
    int head = nums[low];
    unsigned i(low + 1), j(high);
    while (true)
    {
        while (i <= high && nums[i] <= head)
            ++i;
        while (j >= low && nums[j] > head)
            --j;
        if (i >= j)
        {
            std::swap(nums[low], nums[j]);
            break;
        }
        std::swap(nums[i], nums[j]);
    }
    return j;
}

void quickSort(std::vector<int> &nums, unsigned low, unsigned high)
{
    if (low >= high)
        return;
    int idx = partition(nums, low, high);
    quickSort(nums, low, idx - 1);
    quickSort(nums, idx + 1, high);
}

/*
 * 归并排序
 */
void merge(std::vector<int> &nums, unsigned low, unsigned mid, unsigned high)
{
    for (unsigned i = low; i <= high; ++i)
        aux[i] = nums[i];

    unsigned i(low), j(mid + 1), idx(low);
    while (i <= mid || j <= high)
    {
        if (i > mid)
            nums[idx++] = aux[j++];
        else if (j > high)
            nums[idx++] = aux[i++];
        else if (nums[i] <= nums[j])
            nums[idx++] = aux[i++];
        else
            nums[idx++] = aux[j++];
    }
}

void mergeSort(std::vector<int> &nums, unsigned low, unsigned high)
{
    if (low >= high)
        return;
    unsigned mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
} // namespace sort