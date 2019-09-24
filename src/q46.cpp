/*
 * 把数字翻译成字符串
 * @Author: garryfang 
 * @Date: 2019-09-24 16:39:50 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-24 17:19:13
 */

#include <vector>
#include <string>
#include <iostream>

int getTranslationCount(const std::string &s)
{
    if (s.empty() || !isdigit(s.back()))
        return 0;
    std::vector<int> dp(s.size() + 1, 1);
    for (int i = s.size() - 2; i >= 0; --i)
    {
        if (!isdigit(s[i]))
            return 0;
        int cnt = dp[i + 1];
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '5'))
            cnt += dp[i + 2];
        dp[i] = cnt;
    }
    return dp[0];
}
