/*
 * 删除链表的节点
 * @Author: garryfang 
 * @Date: 2019-09-26 16:25:36 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 16:28:25
 */

#include "ListNode.h"

void deleteNode(ListNode *&head, ListNode *pToBeDeleted)
{
    if (!head || !pToBeDeleted)
        return;
    if (pToBeDeleted->next)
    {
        ListNode *temp = pToBeDeleted->next;
        pToBeDeleted->value = pToBeDeleted->next->value;
        pToBeDeleted->next = pToBeDeleted->next->next;
        delete temp;
    }
    else if (head == pToBeDeleted)
    {
        delete pToBeDeleted;
        head = nullptr;
        pToBeDeleted = nullptr;
    }
    else
    {
        ListNode *node = head;
        while (node && node->next != pToBeDeleted)
            node = node->next;
        if (!node)
            return;
        delete pToBeDeleted;
        node->next = nullptr;
        pToBeDeleted = nullptr;
    }
}