/*
 * 从上到下打印二叉树
 * @Author: garryfang 
 * @Date: 2019-09-04 19:03:36 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 19:46:37
 */

#include <queue>
#include <iostream>
#include "BinaryTreeNode.h"

void printFromTopToBottom(BinaryTreeNode *root)
{
    if (!root)
        return;

    std::queue<BinaryTreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        BinaryTreeNode *node = queue.front();
        std::cout << node->value << " ";
        queue.pop();
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
}