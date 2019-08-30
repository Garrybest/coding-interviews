/*
 * 链表中环的入口节点
 * @Author: garryfang 
 * @Date: 2019-08-30 21:56:17 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-30 22:21:06
 */
#include "ListNode.h"

ListNode *meetingNode(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *slow = head, *fast = head;
    do
    {
        if (!fast || !fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast);

    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}