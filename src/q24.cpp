/*
 * @Author: garryfang 
 * @Date: 2019-08-31 09:18:05 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 09:26:15
 */
#include "ListNode.h"

ListNode *reverseList(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode *left = pHead, *right = pHead->next;
    while (right)
    {
        ListNode *next = right->next;
        right->next = left;
        left = right;
        right = next;
    }
    return left;
}