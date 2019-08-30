/*
 * 链表中倒数第k个节点
 * @Author: garryfang 
 * @Date: 2019-08-30 21:39:18 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-08-30 21:53:40
 */

struct ListNode
{
    int value;
    ListNode *next;
};

ListNode *findKthToTail(ListNode *head, unsigned int k)
{
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