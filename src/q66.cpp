/*
 * 构建乘积数组
 * @Author: garryfang 
 * @Date: 2019-09-18 19:05:40 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-18 19:28:35
 */

#include <vector>

std::vector<double> multiply(const std::vector<double> &array)
{
    std::vector<double> v(array.size());
    if (array.empty())
        return v;
    v[0] = 1;
    for (unsigned i = 1; i < array.size(); ++i)
        v[i] = v[i - 1] * array[i - 1];

    double temp = 1;
    for (int i = array.size() - 2; i >= 0; --i)
    {
        temp *= array[i + 1];
        v[i] *= temp;
    }
    return v;
}