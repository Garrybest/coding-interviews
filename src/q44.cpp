/*
 * 数字序列中某一位的数字
 * @Author: garryfang 
 * @Date: 2019-09-26 11:13:13 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 12:52:53
 */

#include <iostream>

int maxIndex(int i)
{
    if (i == 1)
        return 10;
    else if (i == 2)
        return 180;
    else
    {
        int max = i;
        for (int j = 0; j < i - 1; ++j)
            max *= 10;
        return max;
    }
}

int beginIndex(int i)
{
    if (i == 1)
        return 0;
    else
    {
        int begin = 1;
        for (int j = 0; j < i - 1; ++j)
            begin *= 10;
        return begin;
    }
}

int digitIndex(int index)
{
    if (index < 0)
        return -1;
    int i = 1;
    while (true)
    {
        int maxIdx = maxIndex(i);
        if (index >= maxIdx)
        {
            ++i;
            index -= maxIdx;
        }
        else
        {
            int num = beginIndex(i) + index / i;
            int j = i - index % i - 1;
            for (int k = 0; k < j; ++k)
                num /= 10;
            return num % 10;
        }
    }
    return -1;
}
