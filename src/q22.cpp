/*
 * 链表中倒数第k个节点
 * @Author: garryfang 
 * @Date: 2019-08-30 21:39:18 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-30 21:58:04
 */
#include "ListNode.h"

ListNode *findKthToTail(ListNode *head, unsigned int k)
{
    if (!head)
        return nullptr;
    ListNode *left = head, *right = head;
    while (k > 0)
    {
        if (!right)
            return nullptr;
        right = right->next;
        --k;
    }
    while (right)
    {
        left = left->next;
        right = right->next;
    }
    return left;
}