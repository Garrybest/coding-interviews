/*
 * 翻转字符串
 * @Author: garryfang 
 * @Date: 2019-09-20 12:48:50 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-20 14:20:05
 */

#include <string>
#include <iostream>
#include <algorithm>

void reverse(std::string &s)
{
    if (s.empty())
        return;
    std::reverse(s.begin(), s.end());
    auto l = s.begin(), r = s.end();
    while (r != s.end())
    {
        while (l != s.end() && *l == ' ')
            ++l;
        if (l == s.end())
            break;
        for (r = l; r != s.end() && *r != ' '; ++r)
            ++r;
        std::reverse(l, r);
    }    
}