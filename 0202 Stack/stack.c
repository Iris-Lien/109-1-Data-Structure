#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct Stack
{
    int data[SIZE];
    int top;
};
int push(struct Stack *stack, int data)
{
    struct Stack *temp = malloc(sizeof(struct Stack));

    if(temp == stack->data[SIZE-1]) // Checking Array is full or not.
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
    //struct Stack *temp;
    int temp = stack->top;
    if(stack->top == 0) // Checking  is empty or not.
    {
        return NULL;
    }
    else
    {
        stack->top -= 1; //	top = top - 1
        return &stack->data[temp] ;
    }
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
