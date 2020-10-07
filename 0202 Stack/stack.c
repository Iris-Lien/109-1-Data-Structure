#include <stdio.h>
#include <string.h>
#define SIZE 100

struct Stack
{
    int data[SIZE];
    int top;
};

int push(struct Stack *stack, int data)
{
    if(stack->top == stack->data[99]) // Checking Array is full or not.
    {
        return -1;
    }
    else
    {
        stack->top += 1; // top = top + 1
        stack->data[stack->top] = data;
        return 1 ;
    }
}

int *pop(struct Stack *stack)
{
    int *item;
    if(stack->top == 0) // Checking Array is empty or not.
    {
        return NULL;
    }
    item = &stack->data[stack->top] ;
    stack->top -= 1; //	top = top - 1
    return item ;
}

int main()
{
    int data, *temp;
    char command[50];
    struct Stack stack;
    stack.top = 0;
    while(1)
    {
        scanf("%s", command);
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "push") == 0)
        {
            printf("Please input a integer data:");
            scanf("%d", &data);
            if(push(&stack, data) == 1)
            {
                printf("Successfully push data %d into stack.\n",data);
            }
            else
            {
                printf("Failed to push data into stack.\n");
            }
        }
        else if(strcmp(command, "pop") == 0)
        {
            temp = pop(&stack);
            if(temp == NULL)
            {
                printf("Failed to pop a data from stack.\n");
            }
            else
            {
                printf("Pop data %d from stack.\n", *temp);
            }
        }
    }
}
