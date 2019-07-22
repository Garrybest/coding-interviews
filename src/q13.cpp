#include <iostream>
#include <vector>

int movingCount(int threshold, int rows, int cols)
{
    if (rows <= 0 || cols <= 0 || threshold < 0)
        return 0;
    std::vector<std::vector<bool>> visited(rows, std::vector(cols, false));
    return movingCountCore(0, 0, threshold, rows, cols, visited);
}

int movingCountCore(int i, int j, int threshold, int rows, int cols, std::vector<std::vector<bool>> &visited)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || !check(i, j, threshold))
        return 0;
    visited[i][j] = true;
    return movingCountCore(i + 1, j, threshold, rows, cols, visited) +
           movingCountCore(i - 1, j, threshold, rows, cols, visited) +
           movingCountCore(i, j + 1, threshold, rows, cols, visited) +
           movingCountCore(i, j - 1, threshold, rows, cols, visited) + 1;
}

bool check(int i, int j, int threshold)
{
    int sum = 0;
    while (i != 0)
    {
        sum += i % 10;
        i /= 10;
    }
    while (j != 0)
    {
        sum += j % 10;
        j /= 10;
    }
    return sum <= threshold;
}