/*
 * 删除排序链表中重复的节点
 * @Author: garryfang 
 * @Date: 2019-09-27 10:05:23 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-27 11:06:03
 */

#include "ListNode.h"

void deleteHead(ListNode *&head)
{
    int val = head->value;

    while (head && head->value == val)
    {
        ListNode *temp = head->next;
        delete head;
        head = temp;
    }
}

void deleteDupNode(ListNode *pre)
{
    ListNode *node = pre->next;
    int val = node->value;

    while (node && node->value == val)
    {
        ListNode *temp = node->next;
        delete node;
        node = temp;
    }
    pre->next = node;
}

void deleteDuplication(ListNode *&head)
{
    while (head && head->next && head->value == head->next->value)
        deleteHead(head);
    if (!head)
        return;
    ListNode *pre = head, *node = pre->next;
    while (node)
    {
        if (node->next && node->value == node->next->value)
        {
            deleteDupNode(pre);
            node = pre->next;
        }
        else
        {
            pre = node;
            node = node->next;
        }
    }
}