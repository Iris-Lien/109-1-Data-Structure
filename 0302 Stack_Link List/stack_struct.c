#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *head, *top;
};

int push(struct Stack *stack, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        return -1;
    }
    else
    {
        temp->data = data;
        temp->next = stack->top;
        stack->top = temp;
        return 1;
    }
}

int *pop(struct Stack *stack)
{
    struct Node *temp;
    temp = stack->top;
    if(temp == NULL)  //check is empty or not
    {
        return NULL;
    }
    else
    {
        stack->top = stack->top->next;
        return temp;
    }
}

int main()
{
    int data, *temp;
    char command[50];
    struct Stack stack;
    stack.head = NULL;
    stack.top = NULL;
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
                printf("Successfully push data %d into stack.\n");
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
