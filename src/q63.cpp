/*
 * 股票的最大利润
 * @Author: garryfang 
 * @Date: 2019-09-18 20:00:01 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-18 20:22:05
 */

#include <vector>
#include <climits>

int maxDiff(std::vector<int> prices)
{
    int dp_i_0(0), dp_i_1(INT_MIN);
    for (auto &&price : prices)
    {
        dp_i_0 = std::max(dp_i_0, dp_i_1 + price);
        dp_i_1 = std::max(dp_i_1, -price);
    }
    return dp_i_0;
}
