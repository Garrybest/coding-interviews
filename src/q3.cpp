/*
 * 数组中重复的数字
 * @Author: garryfang 
 * @Date: 2019-08-31 10:34:53 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 10:59:22
 */

#include <vector>

int duplicate(std::vector<unsigned int> &numbers)
{
    for (auto &&number : numbers)
    {
        if (number >= numbers.size())
            return -1;
    }

    for (size_t i = 0; i < numbers.size();)
    {
        if (numbers[i] == i)
            ++i;
        else if (numbers[i] == numbers[numbers[i]])
            return numbers[i];
        else
            std::swap(numbers[i], numbers[numbers[i]]);
    }
    return -1;
}