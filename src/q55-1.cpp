/*
 * 二叉树的深度
 * @Author: garryfang 
 * @Date: 2019-09-21 11:47:05 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 11:49:33
 */

#include <BinaryTreeNode.h>
#include <algorithm>

int TreeDepth(BinaryTreeNode *root)
{
    if (!root)
        return 0;
    return std::max(TreeDepth(root->left), TreeDepth(root->right)) + 1;
}