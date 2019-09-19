/*
 * 圆圈中最后剩下的数字
 * @Author: garryfang 
 * @Date: 2019-09-19 10:01:45 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-19 15:53:07
 */

int lastRemaining(unsigned n, unsigned m)
{
    if (n <= 0 || m <= 0)
        return -1;

    int ans = 0;
    for (unsigned i = 2; i <= n; ++i)
        ans = (ans + m) % n;
    return ans;
}