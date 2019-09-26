/*
 * 删除链表的节点
 * @Author: garryfang 
 * @Date: 2019-09-26 16:25:36 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-26 16:28:25
 */

#include "ListNode.h"

void deleteNode(ListNode *&head, ListNode *deleted_node)
{
    if (!head || !deleted_node)
        return;
    ListNode *node = head;
    while (node && node != deleted_node)
        node = node->next;
    if (node == nullptr)
        return;
    if (node == head)
    {
        head = head->next;
        delete node;
    }
    else
    {
        
    }
}