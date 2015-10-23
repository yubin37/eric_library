/*******************************************************************************
 * File name:    stack.c
 *
 * Author:       Yang Yubin
 *
 * Email:        yangyubin1993@gmail.com
 * ****************************************************************************/

#include "stack.h"

#include <stdlib.h>

Stack* top(Stack* head)
{
    if (empty(head) == 1)
    {
        return NULL;
    }

    return head->next;
}

Stack* pop(Stack* head)
{
    if (empty(head) == 1)
    {
        return NULL;
    }

    Stack *temp = head->next;
    head->next = temp->next;
    head->next->prev = head;
    return temp;
}

void push(Stack* head, Stack* node)
{
    node->next = head->next;
    node->next->prev = node;
    head->next = node;
    node->prev = head;
}

int empty(Stack *head)
{
    if (head->next == head)
    {
        return 1;
    }
    return 0;
}
