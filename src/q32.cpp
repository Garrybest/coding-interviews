/*
 * 从上到下打印二叉树
 * @Author: garryfang 
 * @Date: 2019-09-04 19:03:36 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 19:12:16
 */

#include <stack>
#include <iostream>
#include "BinaryTreeNode.h"

void printFromTopToBottom(BinaryTreeNode *root)
{
    if (!root)
        return;

    std::stack<BinaryTreeNode *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        BinaryTreeNode *node = stack.top();
        std::cout << node->value << " ";
        stack.pop();
        if (node->left)
            stack.push(node->left);
        if (node->right)
            stack.push(node->right);
    }
}