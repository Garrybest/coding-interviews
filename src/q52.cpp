/*
 * 两个链表的第一个公共节点
 * @Author: garryfang 
 * @Date: 2019-09-21 19:10:22 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-21 19:52:06
 */

#include <ListNode.h>

ListNode *findFirstCommonNode(ListNode *head1, ListNode *head2)
{
    if (!head1 || !head2)
        return nullptr;
    ListNode *p1 = head1, *p2 = head2;
    while (p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (!p1)
        p1 = head2;
    if (!p2)
        p2 = head1;
    while (p1 != p2)
    {
        if (!p1 || !p2)
            return nullptr;
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}