/*
 * 字符串的排列
 * @Author: garryfang 
 * @Date: 2019-09-05 14:13:14 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 14:23:23
 */

#include <string>
#include <iostream>

void permutation(std::string &str, std::string::iterator begin)
{
    if (begin == str.end()) {
        std::cout << str << " ";
        return;
    }
    permutation(str, begin + 1);
    for (auto iter = begin + 1; iter != str.end(); ++iter)
    {
        if (*iter != *begin) {
            std::swap(*iter, *begin);
            permutation(str, begin + 1);
            std::swap(*iter, *begin);            
        }
    }    
}

void permutation(std::string &str)
{
    if (str.empty())
        return;
    permutation(str, str.begin());
}
