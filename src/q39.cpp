/*
 * 数组中出现次数超过一半的数字
 * @Author: garryfang 
 * @Date: 2019-09-05 20:26:14 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 20:28:16
 */

#include <vector>
#include <stdexcept>

int moreThanHalfNum(std::vector<int> numbers)
{
    if (numbers.empty())
        throw std::invalid_argument("Empty array.");
    int num(0), cnt(0);
    for (auto &&i : numbers)
    {
        if (cnt == 0)
        {
            ++cnt;
            num = i;
        }
        else if (i == num)
            ++cnt;
        else
            --cnt;
    }

    cnt = 0;
    for (auto &&i : numbers)
        if (i == num)
            ++cnt;

    if (cnt * 2 <= numbers.size())
        throw std::invalid_argument("Array not matched.");
    return num;
}