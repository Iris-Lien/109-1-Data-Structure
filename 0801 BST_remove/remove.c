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
    while(tmp != NULL)  //���̭����X��n
    {
        if(tmp->data == n)
        {
            num++;  //��� n
            tmp = tmp->left; //�������~���
        }
        else         //�Ҧb���`�I����n
        {
            if(tmp->data > n) //n�p��root,������
                tmp = tmp->left;
            else    //n�j��root,���k��
                tmp = tmp->right;
        }
    }

    int t = num;
    while(t--)
    {
        tmp = *root;
        struct Node *pre = NULL;   //�M��,�H�K�Ψ�W�@����pre
        while(tmp != NULL)  //��n���Ҧb�`�I
        {
            if(tmp->data == n)
                break;
            else
            {
                pre = tmp;   //�p�G�S���,�� pre ���V�ثe����m�A�e�i
                if(tmp->data > n)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
        }
        r = tmp; //root->data = n
        if(r->right == NULL)   //�N��n�R�����I�S���k�`�I
            next = r->left;
        else if(r->left == NULL) //�N��n�R�����I�S�����`�I
            next = r->right;
        else    //�n�R�����`�I�����k�`�I
        {
            pre = r;
            tmp = r->left;
            while(tmp->right != NULL)   //�M�䥪�l�𤤳̤j�`�I
            {
                pre = tmp;
                tmp = tmp->right;
            }
            r->data = tmp->data;
            r = tmp;   //�Nr���V����̤j���`�I
            next = tmp->left;
        }
        if(pre == NULL) //n�b�̤j�����`�I
        {
            if(r->left==NULL && r->right==NULL)  //�u���@�Ӥ��`�I
                *root = NULL;
            else //�u���@��l�`�I
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
