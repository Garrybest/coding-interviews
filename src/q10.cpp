/*
 * 求斐波那契数列的第n项
 * @Author: garryfang 
 * @Date: 2019-09-02 10:54:05 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 11:07:29
 */
#include <stdexcept>

uint64_t fibonacci(unsigned int n)
{
    if (n < 0)
        throw std::invalid_argument("Invalid input.");
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    uint64_t fib_N(1), fib_N_minus_1(1), fib_N_minus_2(0);
    for (unsigned int i = 2; i <= n; ++i)
    {
        fib_N = fib_N_minus_1 + fib_N_minus_2;
        fib_N_minus_2 = fib_N_minus_1;
        fib_N_minus_1 = fib_N;
    }
    return fib_N;
}