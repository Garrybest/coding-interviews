/*
 * 二叉树的镜像
 * @Author: garryfang 
 * @Date: 2019-09-02 21:53:57 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-02 21:58:24
 */

#include "BinaryTreeNode.h"

void mirror(BinaryTreeNode *root)
{
    if (!root)
        return;
    BinaryTreeNode *temp(root->left);
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}