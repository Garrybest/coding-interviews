/*
 * 之字形打印二叉树
 * @Author: garryfang 
 * @Date: 2019-09-04 19:42:30 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 19:58:17
 */

#include <stack>
#include <iostream>
#include "BinaryTreeNode.h"

void printInSOrder(BinaryTreeNode *root)
{
    if (!root)
        return;
    std::stack<BinaryTreeNode *> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty() || !stack2.empty())
    {
        if (!stack1.empty())
        {
            while (!stack1.empty())
            {
                BinaryTreeNode *node = stack1.top();
                std::cout << node->value << " ";
                if (node->left)
                    stack2.push(node->left);
                if (node->right)
                    stack2.push(node->right);
                stack1.pop();
            }
            std::cout << std::endl;
        }
        else if (!stack2.empty())
        {
            while (!stack2.empty())
            {
                BinaryTreeNode *node = stack2.top();
                std::cout << node->value << " ";
                if (node->right)
                    stack1.push(node->right);
                if (node->left)
                    stack1.push(node->left);
                stack2.pop();
            }
            std::cout << std::endl;
        }
    }
}