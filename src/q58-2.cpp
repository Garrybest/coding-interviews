/*
 * 左旋转字符串
 * @Author: garryfang 
 * @Date: 2019-09-20 14:26:09 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-20 14:33:03
 */

#include <string>
#include <algorithm>
#include <iostream>

void leftRotateString(std::string &s, unsigned n)
{
    if (s.empty())
        return;
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + s.size() - n);
    std::reverse(s.begin()+ s.size() - n, s.end());    
}
