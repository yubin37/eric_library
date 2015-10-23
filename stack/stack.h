/*******************************************************************************
 * Copyright (C), 1996-2015, TP-LINK TECHNOLOGIES CO., LTD.
 *
 * File name:    stack.h
 *
 * Author:       Yang Yubin
 *
 * Email:        yangyubin1993@gmail.com
 * ****************************************************************************/

#ifndef _STACK_INCLUDE_H_
#define _STACK_INCLUDE_H_

/*******************************************************************************
 * stack structure. struct stack should be embeded in the user-define structure
 * ****************************************************************************/
typedef struct stack
{
    struct stack* next;
    struct stack* prev;
} Stack;

#define STACK_HEAD_INIT(name)  {&(name), &(name)}
#define STACK_HEAD(name)    \
    Stack (name) = STACK_HEAD_INIT(name);

#ifdef __cplusplus
extern "C" {
#endif

/* init stack */
static void inline INIT_STACK_HEAD(Stack* head)
{
    head->next = head;
    head->prev = head;
}

#define stack_entry(ptr, type, member)     \
            ((type*)((char*)(ptr) - (unsigned long)(&((type*)0)->member)))

/*******************************************************************************
 * Function:     top(STACK*)
 * Description:  get the top of stack
 * Input:        @head : the head of stack
 * Return:       the top of stack, if stack is empty, return null
 * ****************************************************************************/
Stack* top(Stack* head);

/*******************************************************************************
 * Function:     pop(Stack*)
 * Description:  pop the top element of stack
 * Input:        @head: the head of stack
 * Return:       the top element of stack, if stack is empty, return null
 * ****************************************************************************/
Stack* pop(Stack* head);

/*******************************************************************************
 * Function:     push(Stack*, Stack*)
 * Description:  push the element into the stack
 * Input:        @head: the head of stack
 *               @node: the node to be pushed
 * ****************************************************************************/
void push(Stack* head, Stack* node);

/*******************************************************************************
 * Function:     empty(Stack*)
 * Description:  test whether the stack is empty or not
 * Input:        @head: the head of stack
 * Return:       if stack is empty, return 1, otherwise return 0
 * ****************************************************************************/
int empty(Stack* head);

#ifdef __cplusplus
}
#endif

#endif  /* _STACK_INCLUDE_H_  */
