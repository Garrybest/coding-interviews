/*
 * 不用加减乘除做加法
 * @Author: garryfang 
 * @Date: 2019-09-18 19:39:56 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-18 19:59:17
 */

int add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return num1;
}
