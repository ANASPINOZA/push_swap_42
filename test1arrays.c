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

int mystack[STACK_LENGTH];
int top = EMPTY;

bool push(int value)
{
    if (top >= STACK_LENGTH - 1)
        return false;
    top++;
    mystack[top] = value;
    return true;
}

int pop()
{
    if (top == EMPTY)
        return STACK_EMPTY;
    int result = mystack[top];
    top--;
    return result;
}


int main()
{
    push(88);
    push(11);
    push(79);

    int t;

    while ((t = pop()) != STACK_EMPTY)
    {
       printf("t = %d\n",t);
    }
}
