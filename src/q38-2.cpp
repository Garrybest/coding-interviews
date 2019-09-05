/*
 * 字符串的组合
 * @Author: garryfang 
 * @Date: 2019-09-05 14:24:27 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 15:28:51
 */

#include <map>
#include <iostream>

void combination(std::string &buffer, std::map<char, unsigned> &map, std::map<char, unsigned>::iterator begin)
{
    if (begin == map.end())
    {
        if (!buffer.empty())
            std::cout << buffer << " ";
        return;
    }
    char c = begin->first;
    unsigned num = begin->second;
    combination(buffer, map, ++begin);
    for (unsigned i = 0; i < num; ++i)
    {
        buffer.push_back(c);
        combination(buffer, map, begin);
    }
    for (unsigned i = 0; i < num; ++i)
        buffer.pop_back();    
}

void combination(std::string &str)
{
    if (str.empty())
        return;
    std::string buffer;
    std::map<char, unsigned> map;
    for (auto &c : str)
        ++map[c];
    combination(buffer, map, map.begin());
}
