#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// #ifndef __cplusplus
// typedef unsigned char bool;
// static const bool False = 0;
// static const bool True = 1;
// #endif

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node{   
int data;
struct node *next;
}nodes_t;

typedef nodes_t *stack;

// nodes_t *head = NULL; /*working in with single stak */

bool push(stack *mystack, int value)
{
    nodes_t *new_node = malloc(sizeof(nodes_t));
    if (new_node == NULL)
    return false;
    new_node->data = value;
    
    new_node->next = *mystack;
    *mystack = new_node;
    return true;
}

int pop(stack *mystack)
{
    if (*mystack == NULL)
        return STACK_EMPTY;
    int result = (*mystack)->data;
    nodes_t *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}


int main()
{
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 3);
    push(&s1, 2);
    push(&s1, 1);
    push(&s2, 6);
    push(&s2, 5);
    push(&s2, 4);
    push(&s3,9);
    push(&s3,8);
    push(&s3,7);

    int t;

    while ((t = pop(&s2)) != STACK_EMPTY)
    {
       printf("t = %d\n",t);
    }
}
