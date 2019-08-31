/*
 * @Author: garryfang 
 * @Date: 2019-08-31 09:46:00 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 10:23:38
 */
#include "BinaryTreeNode.h"

bool doesTree1HasTree2(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (!root2)
        return true;
    if (!root1)
        return false;
    if (root1->value != root2->value)
        return false;
    return doesTree1HasTree2(root1->left, root2->left) && doesTree1HasTree2(root1->right, root2->right);
}

bool hasSubTree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (!root2)
        return true;
    if (!root1)
        return false;
    return doesTree1HasTree2(root1, root2) || hasSubTree(root1->left, root2) || hasSubTree(root1->right, root2);
}