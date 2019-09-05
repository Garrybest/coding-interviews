/*
 * 二叉搜索树与双向链表
 * @Author: garryfang 
 * @Date: 2019-09-05 13:08:52 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 13:14:42
 */

#include <utility>
#include "BinaryTreeNode.h"

std::pair<BinaryTreeNode *, BinaryTreeNode *> convertCore(BinaryTreeNode *root)
{
    if (!root)
        return {nullptr, nullptr};
    auto &&left = convertCore(root->left), &&right = convertCore(root->right);
    std::pair<BinaryTreeNode *, BinaryTreeNode *> range{root, root};
    if (left.second)
    {
        left.second->right = root;
        root->left = left.second;
        range.first = left.first;
    }
    if (right.first)
    {
        right.first->left = root;
        root->right = right.first;
        range.second = right.second;
    }

    return std::move(range);
}

BinaryTreeNode *convert(BinaryTreeNode *root)
{
    if (!root)
        return nullptr;
    return convertCore(root).first;
}
