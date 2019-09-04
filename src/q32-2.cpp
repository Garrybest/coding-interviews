/*
 * 分行从上到下打印二叉树
 * @Author: garryfang 
 * @Date: 2019-09-04 19:13:00 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 19:34:51
 */

#include <iostream>
#include <stack>
#include "BinaryTreeNode.h"

void print(BinaryTreeNode *root)
{
    if (!root)
        return;
    std::stack<BinaryTreeNode *> stack;
    stack.push(root);

    unsigned cnt(1);

    while (!stack.empty())
    {
        BinaryTreeNode *node = stack.top();
        std::cout << node->value << " ";

        stack.pop();

        if (node->left)
            stack.push(node->left);
        if (node->right)
            stack.push(node->right);

        if (--cnt == 0)
        {
            cnt = stack.size();
            std::cout << std::endl;
        }
    }
}