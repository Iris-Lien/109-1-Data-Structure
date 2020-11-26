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

void inorder(struct Node *root) //root->¥ª¤l¾ð->¥k¤l¾ð
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d",(root->data));
        inorder(root->right);
    }
}

void preorder(struct Node *root)    //root->¥ª¤l¾ð->¥k¤l¾ð
{
    if(root != NULL)
    {
        printf("%d",(root->data));
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)   //¥ª¤l¾ð->¥k¤l¾ð->root
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",(root->data));
    }
}

int height(struct Node *root)
{
    if(root!=NULL)
    {
        int left_h = height(root->left);
        int right_h = height(root->right);

        if(left_h > right_h)
            return left_h+1;
        else
            return right_h+1;
    }
}

void levelorder(struct Node *root)  //¼h§Ç¹M¾ú
{

}

int main()
{
    struct Node *tree = NULL, *node;
    int j;
    srand(time(NULL));
    for(j = 0; j < 10; j ++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = rand();
        node->left = NULL;
        node->right = NULL;
        insert(&tree, node);
    }
    inorder(tree);
    printf("\n");
    preorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");
    levelorder(tree);
    printf("\n");
}
