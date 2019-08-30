/*
 * 矩阵中的路径
 * @Author: garryfang 
 * @Date: 2019-08-30 21:22:52 
 * @Last Modified by:   garryfang 
 * @Last Modified time: 2019-08-30 21:22:52 
 */
#include <iostream>
#include <vector>

bool hasPathCore(int i, int j, char **matrix, int rows, int cols, int len, char *str, std::vector<std::vector<bool>> &visited)
{
    if (str[len] == '\0')
        return true;
    if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || matrix[i][j] != str[len])
        return false;
    visited[i][j] = true;
    bool hasPath = hasPathCore(i + 1, j, matrix, rows, cols, len + 1, str, visited) ||
                   hasPathCore(i - 1, j, matrix, rows, cols, len + 1, str, visited) ||
                   hasPathCore(i, j + 1, matrix, rows, cols, len + 1, str, visited) ||
                   hasPathCore(i, j - 1, matrix, rows, cols, len + 1, str, visited);
    if (!hasPath)
        visited[i][j] = false;
    return hasPath;
}

bool hasPath(char **matrix, int rows, int cols, char *str)
{
    if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
        return false;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (hasPathCore(i, j, matrix, rows, cols, 0, str, visited))
                return true;
        }
    }
    return false;
}
