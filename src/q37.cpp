/*
 * 二叉树的序列化和反序列化
 * @Author: garryfang 
 * @Date: 2019-09-05 13:41:27 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-05 13:58:25
 */

#include <iostream>
#include <string>
#include "BinaryTreeNode.h"

void serialize(BinaryTreeNode *root)
{
    if (!root)
    {
        std::cout << "$ ";
        return;
    }
    std::cout << root->value << " ";
    serialize(root->left);
    serialize(root->right);
}

BinaryTreeNode *deserialize()
{
    std::string s;
    std::cin >> s;
    if (s == "$")
        return nullptr;
    int value = std::stoi(s);
    BinaryTreeNode *node = new BinaryTreeNode{value, nullptr, nullptr, nullptr};
    node->left = deserialize();
    node->right = deserialize();
    return node;
}
