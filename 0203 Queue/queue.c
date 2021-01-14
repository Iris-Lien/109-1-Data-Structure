#include<stdio.h>
#include<string.h>

#define SIZE 100

struct Queue
{
    int data[SIZE];
    int top, bot;
};

int enqueue(struct Queue *queue, int data)
{
    struct Queue *temp = malloc(sizeof(struct Queue));

    queue->bot = (queue->bot+1)%SIZE;
    if (temp == queue->data[SIZE-1])/*If queue is full */
        return -1;
    queue->bot++;
    queue->data[queue->bot] = data;
    return 1;
}

int *dequeue(struct Queue *queue)
{
    if (queue->top == queue->bot) /*If queue is empty*/
        return NULL;
    queue->top = (queue->top+1)%SIZE;
    queue->top++;
    return  &queue->data[queue->top];

}

int main()
{
    int data, *temp;
    char command[50];
    struct Queue queue;
    queue.top = 0;
    queue.bot = 0;
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
                printf("Successfully enqueue data %d into queue.\n",data);
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
