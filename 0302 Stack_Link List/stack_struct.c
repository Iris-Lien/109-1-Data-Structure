#include<stdio.h>
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
    Node *tmp;
    tmp = malloc(sizeof(Node));
    if(tmp == NULL)
    {
        return -1;
    }
    else
    {
        tmp->data = data;   //make a new node
        tmp->next = stack->top;
        stack->top = tmp;   //tmp is top now
        return 1;
    }
}

int *pop(struct Stack *stack)
{
    Node *tmp;
    if(stack->top == NULL)  //check is empty or not
    {
        return NULL;
    }
    else
    {
        tmp = stack->top;
        stack->head = tmp->data;
        stack->top = stack->top->next;
        free(tmp);  //delete tmp
        return &stack->head;
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
