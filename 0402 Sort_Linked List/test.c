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
    int swap = 1;
    while(swap)
    {
        struct Node *curr = *head;
        swap = 0;
        while(curr->next !=NULL)
        {
            if(curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swap = 1;
            }
            curr = curr->next;
        }
    }
}

void selectionSort(struct Node **head)
{
   struct Node *h = (*head);
    struct Node *i, *j;
    i = h;
    int swap = 1;
    while(i != NULL && i->next != NULL)
    {
        j = i->next;
        struct Node *min = i;
        while(j != NULL)
        {
            if(j->data < min->data)
                min = j;
            j = j->next;
        }
        if(min != i)
        {
            int temp;
            temp = min->data;
            min->data = i->data;
            i->data = temp;
        }
        i = i->next;
    }
    (*head) = h;
}

void insertionSort(struct Node **head)
{
     int n;
    struct Node *cur;
    cur = (*head);
    if (cur->next == NULL)
        return;
    else
    {
        struct Node *ptr,*tmp;
        cur = cur->next;

        while(cur != NULL)
        {
            n = 0;
            ptr = cur;
            tmp = cur->pre;
            cur = cur->next;

            while(tmp !=NULL && (tmp->data > ptr->data))	//找到要往前插入的節點
            {
                n++;
                tmp = tmp->pre;
            }

            if(n > 0)
            {
                ptr->pre->next = ptr->next;	//ex.2->5->3->4  將5、4連接
                if (ptr->next != NULL)
                    ptr->next->pre = ptr->pre;

                if (tmp == NULL)	//節點移至最前方(head)
                {
                    tmp = (*head);
                    ptr->pre = NULL;
                    ptr->next = tmp;
                    tmp->pre = ptr;
                    (*head) = ptr;
                }
                else	//節點不是移至最前方(中間) ex.2->5->3->4 將2、3連接
                {
                    tmp = tmp->next;
                    tmp->pre->next = ptr;
                    ptr->pre = tmp->pre;
                    tmp->pre = ptr;
                    ptr->next = tmp;
                }
            }
        }
    }
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

    selectionSort(&head);

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

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

    insertionSort(&head);

    cur = head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
