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
    //Node *tmp;
    //tmp = malloc(sizeof(Node));
    if(stack->head == NULL)
    {
        return -1;
    }
    else
    {
        stack->head->data = data;   //make a new node
        stack->head->next = stack->top;
        stack->top = stack->head;   //tmp is top now
        return 1;
    }
}

int *pop(struct Stack *stack)
{
    //Node *tmp;
    int tmp;
    if(stack->head == NULL)  //check is empty or not
    {
        return NULL;
    }
    else
    {
        stack->head = stack->top;
        stack->top = stack->top->next;
        tmp = stack->head->data;
        free(stack->head);
        return &tmp;
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
