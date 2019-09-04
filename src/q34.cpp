/*
 * 二叉树中和为某一值的路径
 * @Author: garryfang 
 * @Date: 2019-09-04 21:01:39 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 21:13:54
 */

#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"

void findPath(BinaryTreeNode *root, int expectedNum, std::vector<int> &path, int sum)
{
    if (!root)
        return;
    sum += root->value;
    path.push_back(root->value);
    if (sum == expectedNum)
    {
        for (auto &&num : path)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    findPath(root->left, expectedNum, path, sum);
    findPath(root->right, expectedNum, path, sum);
    path.pop_back();
}

void findPath(BinaryTreeNode *root, int expectedNum)
{
    if (!root)
        return;
    std::vector<int> path;
    findPath(root, expectedNum, path, 0);
}