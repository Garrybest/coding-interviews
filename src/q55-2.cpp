/*
 * 平衡二叉树
 * @Author: garryfang 
 * @Date: 2019-09-21 11:50:20 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 12:02:59
 */

#include <BinaryTreeNode.h>
#include <algorithm>

std::pair<bool, int> isBalancedCore(BinaryTreeNode *root)
{
    std::pair<bool, int> pair{true, 0};
    if (!root)
        return pair;
    auto left = isBalancedCore(root->left), right = isBalancedCore(root->right);
    pair.first = left.first && right.first && std::abs(left.second - right.second) <= 1;
    pair.second = std::max(left.second, right.second) + 1;
    return pair;
}

bool isBalanced(BinaryTreeNode *root)
{
    if (!root)
        return true;
    return isBalancedCore(root).first;
}