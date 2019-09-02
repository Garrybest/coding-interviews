/*
 * 对称的二叉树
 * @Author: garryfang 
 * @Date: 2019-09-02 21:59:19 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 22:08:34
 */

#include "BinaryTreeNode.h"

bool isSymmetrical(BinaryTreeNode *left, BinaryTreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right || left->value != right->value)
        return false;
    return isSymmetrical(left->left, right->right) && isSymmetrical(left->right, right->left);
}

bool isSymmetrical(BinaryTreeNode *root)
{
    return isSymmetrical(root, root);
}
