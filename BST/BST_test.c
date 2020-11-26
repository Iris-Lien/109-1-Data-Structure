#include<stdio.h>
#include<stdlib.h>
#include "BST_2.h"

/*
    Binary Search Tree(²��BST)���H�U�S��:
    1. ����l�𪺩Ҧ��`�I����root�Ӫ��p
    2. �k��l�𪺩Ҧ��`�I����root�Ӫ��j
*/

/*struct node
{
    int data;   //�`�I���
    struct node * left;
    struct node * right;
} ;
*/
//typedef struct node node_t;

int compare(void *elementA, void *elementB)
{
    int *a = elementA, *b = elementB;
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

node_t * insertNode(void * element, node_t *root, int(*compare)(void * elementA, void * elementB))
{
    /*�Yroot�����šA�M���l���J�`�I*/
    struct MyNode* r0 = (struct MyNode *)root;
    if(r0)
    {
        int result = compare(element,(void *)r0); /*������j�p���G�A�j��1�A�p��0*/
        /* �P�_�Q�n���J���`�I�b�k�Υ�*/
        if(result == 1) /*�n���J���`�I���j,���J�ܥk��*/
            r0->links->right = insertNode(element,r0->links->right, compare);
        else if(result == -1)   /*�n���J���`�I���p,���J�ܥ���*/
            r0->links->left = insertNode(element,r0->links->left, compare);
        else
        {
            r0 = (node_t *)element;
            r0->links->left = NULL;
            r0->links->right = NULL;
        }
        return (node_t *)r0;
    }
}

node_t * findMinNode(node_t * root) /*��X BST ����ȳ̤p���`�I*/
{
    node_t * current = root;
    struct MyNode* c0 = (struct MyNode *)current;
    /* �M��̥����`�I�Y���̤p�� */
    while (c0 && c0->links->left != NULL)
        c0 = c0->links->left;

    return (node_t *)c0;
}

node_t * findMaxNode(node_t * root) /*��X BST ����ȳ̤j���`�I*/
{
    node_t * current = root;
    struct MyNode* c0 = (struct MyNode *)current;
    /* �M��̥k���`�I�Y���̤j�� */
    while (c0 && c0->links->right != NULL)
        c0 = c0->links->right;

    return (node_t *)c0;
}

node_t * deleteNode(void * element, node_t * root, int(*compare)(void * elementA, void * elementB)) /* �R�� BST �@�Ӹ`�I*/
{
    /* �T�{�Q�n�R�����`�I�O�_�s�bBST��*/
    int *e0 = element;
    struct MyNode* r0 = (struct MyNode *)root;
    node_t * temp;
    struct MyNode* t0 = (struct MyNode *)temp;

    if (r0 == NULL)
        return NULL;

    int ret = compare(element, &(r0->data));

    if (ret == 0)   //���n�R�����`�I
    {

        /* Case: �֦��@�Ӥp�ĩΨS��*/
        if (r0->links->left == NULL)
        {
            t0 = r0->links->right;
            free(r0);
            return (node_t *)t0;
        }
        else if (r0->links->right == NULL)
        {
            t0 = r0->links->left;
            free(r0);
            return (node_t *)t0;
        }

        /* Case: �֦���Ӥp��->�����(�k�l�𤤳̤p�Ȫ��`�I)���N�Q�R���`�I(root)����l*/

        t0 = findMinNode(r0->links->right);    /*����temp���k�l�𤤳̤p�Ȫ��`�I*/
        r0->data = t0->data;    /*�ƻs������data��root��data*/
        r0->links->right = deleteNode(r0->links->right, t0->data, compare);  /*�N�����R��(�A���U�M��O�_���p��)*/

    }
    else if (ret < 0)
    {
        deleteNode(element, r0->links->left, compare);
    }
    else
    {
        deleteNode(element, r0->links->right, compare);
    }

    return (node_t *)r0;
}

node_t * findNode(node_t * root, int key) /* ��X BST �ŦX��Ȫ��`�I*/
{
    struct MyNode* r0 = (struct MyNode *)root;
    /* ���P�_root�O�_����*/
    if(r0)
    {
        /* ���ŦX��Ȫ��`�I,�^��*/
        if(key == r0->data)
            return (node_t *)r0;

        /* �P�_�O�_��root�j,�O���ܩ��k��,�_�h�����M��*/
        if(key > r0->data)
            r0 = r0->links->right;
        else
            r0 = r0->links->left;
    }
    return NULL;
}

void inOrder(node_t * root) /*�C�L�X BST �ھڤ��ǰl�ܪk�C�Ӹ`�I���e*/
{
    struct MyNode* r0 = (struct MyNode *)root;
    if(r0 != NULL)    /*�ˬd�`�I�O�_��NULL*/
    {
        inOrder(r0->links->left);    /*�����l��M�X*/
        printf(" %d ", r0->data); /*��Xdata*/
        inOrder(r0->links->right);   /*���k�l��M�X*/
    }
}

node_t * treeCopy(node_t *original) /*�ƻs*/
{
    struct MyNode* original_t = (struct MyNode *)original;
    node_t *temp;
    struct MyNode* t0 = (struct MyNode *)temp;
    if(original_t)
    {
        t0 = (struct node*)malloc(sizeof(struct node));   /*�t�mtemp���O����*/
        t0->links->left = treeCopy(original_t->links->left);  /*�����ƻs*/
        t0->links->right = treeCopy(original_t->links->right);    /*���k�ƻs*/
        t0->data = original_t->data;    /*�ƻsdata*/
        return (node_t *)t0;
    }
    return NULL;
}

int treeEqual(node_t * root1, node_t * root2) /*����G�� BST �O�_�ۦP*/
{
    /*�p�G�G����root1�Mroot2�ۦP�^��1;
      �_�h�^��0*/

    struct MyNode* r1 = (struct MyNode *)root1;
    struct MyNode* r2 = (struct MyNode *)root2;

    if(r1 && r2)
    {
        if(r1->data == r2->data)
        {
            treeEqual(r1->links->left, r2->links->left);
            treeEqual(r1->links->right, r2->links->right);
            return 1;
        }
    }
    else
        return 0;
}

