/*
 * 二叉树的下一个节点
 * @Author: garryfang 
 * @Date: 2019-09-02 10:28:36 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 10:46:51
 */

#include "BinaryTreeNode.h"

BinaryTreeNode *getNext(BinaryTreeNode *node)
{
    if (!node)
        return nullptr;
    if (node->right)
    {
        BinaryTreeNode *right = node->right;
        while (right->left)
            right = right->left;
        return right;
    }
    else
    {
        BinaryTreeNode *current = node;
        BinaryTreeNode *parent = node->parent;
        while (parent)
        {
            if (current->parent == parent->left)
                return parent;
            current = parent;
            parent = parent->parent;
        }
    }
    return nullptr;
}