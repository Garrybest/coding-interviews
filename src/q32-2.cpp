/*
 * 分行从上到下打印二叉树
 * @Author: garryfang 
 * @Date: 2019-09-04 19:13:00 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 19:45:24
 */

#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

void print(BinaryTreeNode *root)
{
    if (!root)
        return;
    std::queue<BinaryTreeNode *> queue;
    queue.push(root);

    unsigned cnt(1);

    while (!queue.empty())
    {
        BinaryTreeNode *node = queue.front();
        std::cout << node->value << " ";

        queue.pop();

        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);

        if (--cnt == 0)
        {
            cnt = queue.size();
            std::cout << std::endl;
        }
    }
}