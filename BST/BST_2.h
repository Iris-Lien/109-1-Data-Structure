#ifndef BST_2_H_INCLUDED
#define BST_2_H_INCLUDED

/*
    Binary Search Tree(²��BST)���H�U�S��:
    1. ����l�𪺩Ҧ��`�I����root�Ӫ��p
    2. �k��l�𪺩Ҧ��`�I����root�Ӫ��j
*/

struct node
{
    struct node * left;
    struct node * right;
} ;

struct MyNode
{
    struct node * links;
    int data;
};

typedef struct node node_t;

int compare(void *elementA, void *elementB);

node_t * insertNode(void * element, node_t *root, int(*compare)(void * elementA, void * elementB));/*���J�@�Ӹ`�I�i BST ��*/

node_t * findMinNode(node_t * root); /*��X BST ����ȳ̤p���`�I*/

node_t * findMaxNode(node_t * root) ;/*��X BST ����ȳ̤j���`�I*/

node_t * deleteNode(void * element, node_t * root, int(*compare)(void * elementA, void * elementB)) ;/* �R�� BST �@�Ӹ`�I*/


node_t * findNode(node_t * root, int key); /* ��X BST �ŦX��Ȫ��`�I*/

void inOrder(node_t * root); /*�C�L�X BST �ھڤ��ǰl�ܪk�C�Ӹ`�I���e*/

node_t * treeCopy(node_t *original); /*�ƻs*/

int treeEqual(node_t * root1, node_t * root2); /*����G�� BST �O�_�ۦP*/


#endif // BST_2_H_INCLUDED
