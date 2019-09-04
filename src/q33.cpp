/*
 * 二叉搜索树的后序遍历
 * @Author: garryfang 
 * @Date: 2019-09-04 20:14:05 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 20:50:29
 */

#include <vector>
#include "BinaryTreeNode.h"

bool verifySequenceOfBst(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end)
{
    if (begin == end)
        return true;
    int value = *begin;
    auto iter = begin + 1;
    for (; iter != end; ++iter)
    {
        if (*iter < value)
            break;
    }
    for (auto it = iter; it != end; ++it)
    {
        if (*it > value)
            return false;
    }
    return verifySequenceOfBst(begin + 1, iter) && verifySequenceOfBst(iter, end);
}

bool verifySequenceOfBst(std::vector<int> &sequence)
{
    if (sequence.empty())
        return true;
    return verifySequenceOfBst(sequence.rbegin(), sequence.rend());
}
