/*
 * 重建二叉树
 * @Author: garryfang 
 * @Date: 2019-08-31 14:46:03 
 * @Last Modified by:   garryfang 
 * @Last Modified time: 2019-08-31 14:46:03 
 */

#include <vector>
#include <stdexcept>
#include "BinaryTreeNode.h"

BinaryTreeNode *constructCore(std::vector<int>::iterator preorder_start, std::vector<int>::iterator preorder_end,
                              std::vector<int>::iterator inorder_start, std::vector<int>::iterator inorder_end)
{
    if (preorder_start == preorder_end || inorder_start == inorder_end)
        return nullptr;
    BinaryTreeNode *root = new BinaryTreeNode();
    root->value = *inorder_start;

    auto preorder_iter = preorder_start;
    while (true)
    {
        if (preorder_iter == preorder_end)
            throw std::invalid_argument("Invalid Input.");
        if (*preorder_iter == *inorder_start)
            break;
        ++preorder_iter;
    }

    root->left = constructCore(preorder_start, preorder_iter, inorder_start + 1,
                               inorder_start + 1 + (preorder_iter - preorder_start));
    root->right = constructCore(preorder_iter + 1, preorder_end,
                                inorder_start + 1 + (preorder_iter - preorder_start), inorder_end);
    return root;
}

BinaryTreeNode *construct(std::vector<int> &preorder, std::vector<int> &inorder)
{
    if (preorder.size() != inorder.size())
        return nullptr;
    return constructCore(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}