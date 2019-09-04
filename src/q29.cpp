/*
 * 顺时针打印矩阵
 * @Author: garryfang 
 * @Date: 2019-09-04 10:18:03 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 10:53:45
 */
#include <iostream>
#include <vector>

void printOneCircle(std::vector<std::vector<int>> &matrix, int start, int m, int n)
{
    int i(start), j(start);
    for (; j < n - start; ++j)
        std::cout << matrix[i][j] << " ";
    --j;
    ++i;
    for (; i < m - start; ++i)
        std::cout << matrix[i][j] << " ";
    --i;
    if (i == start || j == start)
        return;
    --j;
    for (; j >= start; --j)
        std::cout << matrix[i][j] << " ";
    ++j;
    --i;
    for (; i >= start; --i)
        std::cout << matrix[i][j] << " ";
}

void printMatrixClockInCircle(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty())
        return;
    int m(matrix.size()), n(matrix[0].size());
    for (int i = 0; i < (std::min(m, n) + 1) / 2; ++i)
        printOneCircle(matrix, i, m, n);
}