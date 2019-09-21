/*
 * 二叉搜索树的第k大节点
 * @Author: garryfang 
 * @Date: 2019-09-21 15:21:40 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 15:43:11
 */

#include <BinaryTreeNode.h>

BinaryTreeNode *ans = nullptr;
int idx = 0;

void getNumberSameAsIndexCore(BinaryTreeNode *root, const unsigned num)
{
    if (!root)
        return;
    getNumberSameAsIndexCore(root->left, num);
    ++idx;
    if (idx == num)
        ans = root;
    getNumberSameAsIndexCore(root->right, num);
}

BinaryTreeNode *getNumberSameAsIndex(BinaryTreeNode *root, const unsigned num)
{
    if (!root)
        return nullptr;
    getNumberSameAsIndexCore(root, num);
    return ans;
}
