/*
 * 树中两个节点的最低公共祖先
 * @Author: garryfang 
 * @Date: 2019-09-26 15:20:32 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 16:01:09
 */

#include "BinaryTreeNode.h"

BinaryTreeNode *parent = nullptr;

bool dfs(BinaryTreeNode *root, BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if (!root)
        return false;
    bool left = dfs(root->left, node1, node2), right = dfs(root->right, node1, node2), mid = root == node1 || root == node2;
    if ((left && right) || (left && mid) || (right && mid))
        parent = root;

    return left || right || mid;
}

BinaryTreeNode *lastCommonNodeParent(BinaryTreeNode *root, BinaryTreeNode *node1, BinaryTreeNode *node2)
{
    if (!root || !node1 || !node2)
        return nullptr;
    dfs(root, node1, node2);
    return parent;
}
