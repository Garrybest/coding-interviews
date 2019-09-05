/*
 * 最小的k个数
 * @Author: garryfang 
 * @Date: 2019-09-05 20:40:57 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 22:06:31
 */

#include <iostream>
#include <vector>

unsigned partition(std::vector<int> &numbers, unsigned begin, unsigned end)
{
    if (begin == end)
        return begin;
    int num = numbers[begin];
    unsigned i(begin + 1), j(end);
    while (true)
    {
        while (i <= end && numbers[i] <= num)
            ++i;
        while (numbers[j] > num)
            --j;
        if (i >= j)
            break;
        std::swap(numbers[i], numbers[j]);
    }
    std::swap(numbers[begin], numbers[j]);
    return j;
}

void getLeastNumbers(std::vector<int> &numbers, unsigned k)
{
    if (numbers.empty())
        return;

    unsigned begin(0), end(numbers.size() - 1);
    unsigned idx = partition(numbers, begin, end);

    while (idx + 1 != k)
    {
        std::cout << idx << std::endl;
        if (idx + 1 > k)
            end = idx - 1;
        else
            begin = idx + 1;
        idx = partition(numbers, begin, end);
    }
}
