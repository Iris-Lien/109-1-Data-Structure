#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *top, *bot;
};

int enqueue(struct Queue *queue, int data)
{
    struct Node * in = (struct Node *)malloc(sizeof(struct Node));
    if(in == NULL)
    {
        return -1;
    }
    else
    {
        if(queue->top == NULL && queue->bot == NULL)
            queue->top = queue->bot = in;
        in->data = data;
        queue->bot->next = in;
        queue->bot = in;
        return 1;
    }
}

int *dequeue(struct Queue *queue)
{
    struct Node *out;
    out = queue->top;
    if(out == NULL)  //if queue is empty
    {
        return NULL;
    }
    else
    {
        queue->top = queue->top->next;
        return out;
    }
}

int main()
{
    int data, *temp;
    char command[50];
    struct Queue queue;
    queue.top = NULL;
    queue.bot = NULL;
    while(1)
    {
        scanf("%s", command);
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
        {
            printf("Please input a integer data:");
            scanf("%d", &data);
            if(enqueue(&queue, data) == 1)
            {
                printf("Successfully enqueue data %d into queue.\n");
            }
            else
            {
                printf("Failed to enqueue data into queue.\n");
            }
        }
        else if(strcmp(command, "dequeue") == 0)
        {
            temp = dequeue(&queue);
            if(temp == NULL)
            {
                printf("Failed to dequeue a data from queue.\n");
            }
            else
            {
                printf("Dequeue data %d from queue.\n", *temp);
            }
        }
    }
}


