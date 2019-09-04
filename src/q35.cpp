/*
 * 复杂链表的复制
 * @Author: garryfang 
 * @Date: 2019-09-04 21:19:46 
 * @Last Modified by: garryfang
 * @Last Modified time: 2019-09-04 21:34:50
 */

#include "ComplexListNode.h"

ComplexListNode *cloneNodes(ComplexListNode *head)
{
    if (!head)
        return nullptr;
    ComplexListNode *node = head;
    while (node)
    {
        ComplexListNode *new_node = new ComplexListNode{node->value, node->next, node->random};
        node->next = new_node;
        node = new_node->next;
    }

    node = head->next;
    while (node)
    {
        if (node->random)
            node->random = node->random->next;
        node = node->next->next;
    }

    node = head->next;
    ComplexListNode *new_head = head->next;
    while (node)
    {
        ComplexListNode *new_node = node->next;
        node->next = new_node->next;
        if (new_node->next)
            new_node->next = new_node->next->next;
    }

    return new_head;
}
