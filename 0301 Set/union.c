#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Set
{
    struct Node *element;
};

int addElement(struct Set *set, int e)
{
    if()
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Set *unions(Set *a, Set *b)
{
    Set *c;
    c = *a && *b;
    return
}

Set *intersetcions(Set *a, Set *b)
{
}

int equivalent(Set *a, Set *b)
{
}

int main()
{
    struct Set *a = (struct Set *)malloc(sizeof(struct Set));
    struct Set *b = (struct Set *)malloc(sizeof(struct Set));
    struct Set *c;
    struct Node *cur;

    addElement(a, 1);
    addElement(a, 2);
    addElement(a, 3);
    addElement(b, 3);
    addElement(b, 4);
    addElement(b, 5);
    addElement(b, 5);

    c = unions(a, b);
    cur = c->element;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    c = intersetcions(a, b);
    cur = c->element;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    if(equivalent(a, b) == 0)
        printf("Not equivalent.\n");
    else
        printf("Equivalent!\n");
}
