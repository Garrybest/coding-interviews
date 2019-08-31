/*
 * 从尾到头打印链表
 * @Author: garryfang 
 * @Date: 2019-08-31 11:57:52 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 14:50:38
 */

#include <iostream>
#include "ListNode.h"

void printListReversingly(ListNode *node)
{
    if (!node)
        return;
    printListReversingly(node->next);
    std::cout << node->value << '\t';
}