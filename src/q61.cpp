/*
 * 扑克牌中的顺子
 * @Author: garryfang 
 * @Date: 2019-09-19 14:16:33 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-19 14:29:39
 */

#include <vector>
#include <algorithm>

bool isContinuous(std::vector<int> &numbers)
{
    if (numbers.size() != 5)
        return false;
    std::sort(numbers.begin(), numbers.end());

    int joker(0), diff(0), pre(0);
    for (auto &&num : numbers)
    {
        if (num == 0)
            ++joker;
        else if (pre == 0)
            pre = num;
        else if (num == pre)
            return false;
        else
        {
            diff += num - pre;
            pre = num;
        }
    }
    return joker == diff;
}