/*
 * n个骰子的点数
 * @Author: garryfang 
 * @Date: 2019-09-19 14:41:56 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-19 15:52:37
 */

#include <unordered_map>
#include <vector>
#include <cmath>

std::unordered_map<int, double> probability(int n)
{
    std::unordered_map<int, double> map;
    if (n <= 0)
        return map;

    double sum = pow(6, n);
    int min = n, max = 6 * n;
    std::vector<int> v1(6 * n + 1), v2(6 * n + 1);
    std::vector<int> *p1 = &v1, *p2 = &v2;
    for (int i = 1; i <= 6; ++i)
        v1[i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = i; j <= 6 * i; ++j)
        {
            for (int k = 1; k <= 6 && j - k >= i - 1; ++k)
                (*p2)[j] += (*p1)[j - k];
        }
        std::swap(p1, p2);
    }

    for (int i = min; i <= max; ++i)
        map[i] = (*p1)[i] / sum;

    return map;
}