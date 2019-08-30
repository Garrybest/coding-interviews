/*
 * 剪绳子
 * @Author: garryfang 
 * @Date: 2019-08-30 21:22:55 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-30 21:33:19
 */
#include <iostream>
#include <cmath>

int maxProductAfterCutting(int length)
{
    if (length <= 1)
        return 0;
    else if (length == 2)
        return 1;
    else if (length == 3)
        return 2;
    int timesOf3 = length / 3;
    if (length % 3 == 0)
        return (int)pow(3, timesOf3);
    else if (length % 3 == 1)
        return (int)pow(3, timesOf3 - 1) * 4;
    else
        return (int)pow(3, timesOf3) * 2;
}