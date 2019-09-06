/*
 * 二叉树的前序、中序、后序遍历非递归
 * @Author: garryfang 
 * @Date: 2019-09-06 17:09:13 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-06 21:01:55
 */

#include <iostream>
#include <stack>
#include <BinaryTreeNode.h>

void preOrder(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;
    BinaryTreeNode *p = root;
    while (p || !stack.empty())
    {
        while (p)
        {
            std::cout << p->value << " ";
            stack.push(p);
            p = p->left;
        }
        p = stack.top();
        stack.pop();
        p = p->right;
    }
}

void inOrder(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;
    BinaryTreeNode *p = root;
    while (p || !stack.empty())
    {
        while (p)
        {
            stack.push(p);
            p = p->left;
        }
        p = stack.top();
        stack.pop();
        std::cout << p->value << " ";
        p = p->right;
    }
}

void postOrder(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;
    BinaryTreeNode *p = root, *pre = nullptr;
    while (p || !stack.empty())
    {
        while (p)
        {
            stack.push(p);
            p = p->left;
        }
        p = stack.top();
        if (!p->right || p->right == pre)
        {
            std::cout << p->value << " ";
            stack.pop();
            pre = p;
            p = nullptr;
        }
        else
        {
            p = p->right;
        }
    }
}