/*
 * 二进制中1的个数
 * @Author: garryfang 
 * @Date: 2019-08-31 10:27:10 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 10:32:20
 */

int numberOf1(int n)
{
    int ans = 0;
    while (n)
    {
        n &= n - 1;
        ++ans;
    }
    return ans;
}