#include<stdio.h>
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
    Node *tmp;  //make a new node
    tmp = malloc(sizeof(Node));
    tmp->data = data;   //give the data of the new node
    tmp->next = NULL
    if(queue->bot == NULL)  //if queue is empty
    {
        queue->top = queue->bot = tmp;
        return -1;
    }
    else
    {
        queue->bot->next = tmp;
        queue->bot = tmp;
    }
    return 1;
}

int *dequeue(struct Queue *queue)
{
    Node *tmp;
    if(queue->top == NULL)  //check queue is no new node
    {
        return NULL;
    }
    else
    {
        tmp = queue->top;
        queue->top = queue->top->next;
        free(tmp);
        return  &queue->top->data;
    }
}

int main()
{
    int data, *temp;
    char command[50];
    Queue queue;
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


