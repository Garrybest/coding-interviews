/*
 * 二维数组中的查找
 * @Author: garryfang 
 * @Date: 2019-08-31 11:00:31 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 14:55:06
 */
#include <vector>

bool find(std::vector<std::vector<int>> &matrix, int number)
{
    if (matrix.empty() || matrix[0].empty())
        return false;
    int i(0), j(matrix[0].size() - 1);
    while (i < (int)matrix.size() && j >= 0)
    {
        if (matrix[i][j] == number)
            return true;
        else if (matrix[i][j] > number)
            --j;
        else
            ++i;
    }
    return false;
}