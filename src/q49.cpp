/*
 * 丑数
 * @Author: garryfang 
 * @Date: 2019-09-23 20:35:28 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-23 21:38:04
 */

#include <vector>

int getUglyNum(unsigned index)
{
    unsigned i2 = 0, i3 = 0, i5 = 0;
    int max = 1;
    std::vector<int> ugly(index);
    ugly[0] = 1;
    for (unsigned i = 1; i < index; ++i)
    {
        while (ugly[i2] * 2 <= max) ++i2;
        while (ugly[i3] * 3 <= max) ++i3;
        while (ugly[i5] * 5 <= max) ++i5;
        ugly[i] = std::min(ugly[i2] * 2, std::min(ugly[i3] * 3, ugly[i5] * 5));
        max = ugly[i];
    }
    return max;
}