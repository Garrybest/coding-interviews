/*
 * 字符串中第一个只出现一次的字符
 * @Author: garryfang 
 * @Date: 2019-09-21 20:45:54 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 21:18:26
 */

#include <queue>
#include <string>

char firstAppearingOnce(std::string &s)
{
    int map[256] = {0};
    std::queue<char> queue;
    for (auto &&c : s)
    {
        ++map[(unsigned char)c];
        if (map[(unsigned char)c] == 1)
            queue.push(c);
    }
    while (!queue.empty())
    {
        if (map[(unsigned char)queue.front()] == 1)
            return queue.front();
        queue.pop();
    }
    return '\0';
}