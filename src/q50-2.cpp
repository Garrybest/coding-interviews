/*
 * 字符流中第一个只出现一次的字符
 * @Author: garryfang 
 * @Date: 2019-09-21 21:26:26 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 21:35:19
 */

#include <unordered_map>
#include <queue>

class CharStatistics
{
private:
    std::queue<char> queue;
    std::unordered_map<char, bool> map;

public:
    CharStatistics() {}
    ~CharStatistics() {}

    void insert(char c)
    {
        if (map.find(c) == map.end())
        {
            queue.push(c);
            map.insert({c, true});
        }
        else if (map[c])
            map[c] = false;
    }

    char getFirstChar()
    {
        while (!queue.empty())
        {
            if (map[queue.front()])
                return queue.front();
            queue.pop();
        }
        return '\0';
    }
};
