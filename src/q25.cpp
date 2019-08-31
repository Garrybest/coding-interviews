/*
 * 合并两个排序的链表
 * @Author: garryfang 
 * @Date: 2019-08-31 09:28:11 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-31 09:45:23
 */
#include "ListNode.h"

ListNode *moveNode(ListNode *&node)
{
    ListNode *pre = node;
    node = node->next;
    return pre;
}

ListNode *Merge(ListNode *head1, ListNode *head2)
{
    ListNode *ahead = new ListNode();
    ListNode *node = ahead;
    while (head1 || head2)
    {
        if (!head1)
            node->next = moveNode(head2);
        else if (!head2)
            node->next = moveNode(head1);
        else
        {
            if (head1->value <= head2->value)
                node->next = moveNode(head1);
            else
                node->next = moveNode(head2);
        }
        node = node->next;
    }    
    node = ahead->next;
    delete ahead;
    return node;
}