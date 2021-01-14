#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
    int data, level;
    struct Node *left, *right;
};

void insert(struct Node **root, struct Node *node)
{
    if(*root == NULL)
        *root = node;
    else if(node->data > (*root)->data)
        insert(&((*root)->right), node);
    else
        insert(&((*root)->left), node);
}

struct Node *removal(struct Node **root, int n)
{
    struct Node *r = *root;
    struct Node *next;
    int num = 0;
    struct Node *tmp = r;
    while(tmp != NULL)  //找樹裡面有幾個n
    {
        if(tmp->data == n)
        {
            num++;  //找到 n
            tmp = tmp->left; //往左邊繼續找
        }
        else         //所在的節點不為n
        {
            if(tmp->data > n) //n小於root,往左找
                tmp = tmp->left;
            else    //n大於root,往右找
                tmp = tmp->right;
        }
    }

    int t = num;
    while(t--)
    {
        tmp = *root;
        struct Node *pre = NULL;   //清空,以免用到上一輪的pre
        while(tmp != NULL)  //找n的所在節點
        {
            if(tmp->data == n)
                break;
            else
            {
                pre = tmp;   //如果沒找到,把 pre 指向目前的位置再前進
                if(tmp->data > n)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
        }
        r = tmp; //root->data = n
        if(r->right == NULL)   //代表要刪除的點沒有右節點
            next = r->left;
        else if(r->left == NULL) //代表要刪除的點沒有左節點
            next = r->right;
        else    //要刪除的節點有左右節點
        {
            pre = r;
            tmp = r->left;
            while(tmp->right != NULL)   //尋找左子樹中最大節點
            {
                pre = tmp;
                tmp = tmp->right;
            }
            r->data = tmp->data;
            r = tmp;   //將r指向左樹最大的節點
            next = tmp->left;
        }
        if(pre == NULL) //n在最大的父節點
        {
            if(r->left==NULL && r->right==NULL)  //只有一個父節點
                *root = NULL;
            else //只有一邊子節點
            {
                r->data = next->data;
                r->left = next->left;
                r->right = next->right;
            }
        }
        else if(r == pre->right)
            pre->right = next;
        else
            pre->left = next;
    }
    return num;
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d",(root->data));
        inorder(root->right);
    }
}

int main()
{
    struct Node *tree = NULL, *node;
    int j, k, l;
    srand(time(NULL));
    for(j = 0; j < 10; j ++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = rand() % 10;
        node->left = NULL;
        node->right = NULL;
        insert(&tree, node);
    }
    inorder(tree);
    printf("\n");
    for(j = 0; j < 5; j ++)
    {
        l = rand() % 10;
        k = removal(&tree, l);
        printf("Remove %d(%d)\n", l, k);
    }
    inorder(tree);
    printf("\n");
}
