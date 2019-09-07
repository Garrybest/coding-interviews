/*
 * 大顶堆
 * @Author: garryfang 
 * @Date: 2019-09-06 22:08:46 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-07 09:45:57
 */

#include <vector>
#include <stdexcept>

std::vector<int> heap;

void swim(unsigned k)
{
    while (k > 0)
    {
        if (heap[k] <= heap[(k - 1) / 2])
            break;
        std::swap(heap[k], heap[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

void sink()
{
    unsigned k = 0;
    while (2 * k + 1 < heap.size())
    {
        unsigned j = 2 * k + 1;
        if (j + 1 < heap.size() && heap[j + 1] > heap[j])
            ++j;
        if (heap[k] >= heap[j])
            break;
        std::swap(heap[k], heap[j]);
        k = j;
    }
}

void insert(int val)
{
    heap.push_back(val);
    swim(heap.size() - 1);
}

void deleteMax()
{
    if (heap.empty())
        throw std::runtime_error("Empty heap.");
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    sink();
}