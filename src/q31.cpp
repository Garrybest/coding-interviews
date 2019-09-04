/*
 * 栈的压入、弹出序列
 * @Author: garryfang 
 * @Date: 2019-09-04 16:50:58 
 * @Last Modified by:   garryfang 
 * @Last Modified time: 2019-09-04 16:50:58 
 */

#include <vector>
#include <stack>
#include <iostream>


bool isPopOrder(std::vector<int> &push_order, std::vector<int> &pop_order)
{
    if (push_order.size() != pop_order.size())
        return false;
    std::stack<int> stack;
    auto push_iter = push_order.begin();
    for (auto pop_iter = pop_order.begin(); pop_iter != pop_order.end(); ++pop_iter)
    {
        if (stack.empty() || stack.top() != *pop_iter)
        {
            if (push_iter == push_order.end())
                return false;
            while (*push_iter != *pop_iter)
            {
                if (push_iter == push_order.end())
                    return false;
                stack.push(*push_iter++);
            }
            ++push_iter;
        }
        else
        {
            stack.pop();
        }
    }
    return true;
}
