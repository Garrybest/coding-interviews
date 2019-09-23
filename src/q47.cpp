/*
 * 礼物的最大价值
 * @Author: garryfang 
 * @Date: 2019-09-23 22:11:18 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-23 22:19:01
 */

#include <vector>

unsigned getMaxValue(std::vector<std::vector<unsigned>> &values)
{
    if (values.empty() || values[0].empty())
        return 0;
    unsigned m = values.size(), n = values[0].size();
    std::vector<std::vector<unsigned>> dp(m, std::vector<unsigned>(n));
    for (unsigned i = 0; i < m; ++i)
    {
        for (unsigned j = 0; j < n; ++j)
        {
            unsigned up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = std::max(up, left) + values[i][j];
        }
    }
    return dp[m - 1][n - 1];
}