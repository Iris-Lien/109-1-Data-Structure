#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *pre, *next;
};

void bubbleSort(struct Node **head)
{
    //struct Node* current = *head;
    while((*head) != NULL)
    {
        while((*head)->next != NULL)
        {
            if((*head)->data > (*head)->next->data)
            {
                int temp = (*head)->data;
                (*head)->data = (*head)->next->data;
                (*head)->next->data = temp;
            }
            (*head) = (*head)->next;
        }
    }
}

void selectionSort(struct Node **head)
{
    struct Node* current = *head;
    while(current != NULL)
    {
        int min = current->data;
        while(current->next != NULL)
        {
            if(min > current->next->data)
            {
                min = current->next->data;
                current->next = (*head);
                //min->pre->next =
            }
            else
                current = current->next;
        }
        (*head) = (*head)->next;

    }
}

void insertionSort(struct Node **head)
{
}

int main()
{
    int j;
    struct Node *head, *buf, *cur;

    srand(time(NULL));

    head = NULL;
    for(j = 0; j < SIZE; j ++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if(head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    bubbleSort(&head);

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    /*head = NULL;
    for(j = 0; j < SIZE; j ++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if(head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    selectionSort(&head);

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");*/

    /*head = NULL;
    for(j = 0; j < SIZE; j ++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if(head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    insertionSort(&head);

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");*/
}
