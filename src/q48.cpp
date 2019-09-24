/*
 * 最长不含重复字符的子字符串
 * @Author: garryfang 
 * @Date: 2019-09-23 21:46:52 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-24 17:06:53
 */

#include <string>
#include <unordered_map>

unsigned longestSubstringWithoutDuplication(const std::string &str)
{
    unsigned i = 0, j = 0;
    unsigned ans = 0;
    std::unordered_map<char, unsigned> map;
    while (j < str.length())
    {
        char c = str[j];
        if (map.find(c) != map.end() && map[c] >= i)
            i = map[c] + 1;
        map[c] = j;
        ans = std::max(ans, j - i + 1);
        ++j;
    }
    return ans;
}