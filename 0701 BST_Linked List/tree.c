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

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}
void levelorder(struct Node *root)  //¼h§Ç¹M¾ú
{
    int h = height(root);
    for (int i=1; i<=h; i++)
        printLevel(root, i);
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
