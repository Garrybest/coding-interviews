/*
 * 数值的整数次方
 * @Author: garryfang 
 * @Date: 2019-09-27 10:08:52 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-27 10:20:19
 */

#include <stdexcept>

double powCore(double base, unsigned exp)
{
    if (exp == 1)
        return base;
    double ans = powCore(base, exp / 2);
    ans *= ans;
    if ((exp & 1) == 1)
        ans *= base;
    return ans;
}

double pow(double base, int exp)
{
    if (base == 0. && exp == 0)
        throw std::invalid_argument("Base and exp are both 0.");
    if (exp == 0)
        return 1;
    if (base == 0)
        return 0;
    double ans = powCore(base, std::abs(exp));
    return exp > 0 ? ans : 1 / ans;
}
