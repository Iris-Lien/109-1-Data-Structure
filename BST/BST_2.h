#ifndef BST_2_H_INCLUDED
#define BST_2_H_INCLUDED

/*
    Binary Search Tree(簡稱BST)有以下特性:
    1. 左邊子樹的所有節點都比root來的小
    2. 右邊子樹的所有節點都比root來的大
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

node_t * insertNode(void * element, node_t *root, int(*compare)(void * elementA, void * elementB));/*插入一個節點進 BST 內*/

node_t * findMinNode(node_t * root); /*找出 BST 中鍵值最小的節點*/

node_t * findMaxNode(node_t * root) ;/*找出 BST 中鍵值最大的節點*/

node_t * deleteNode(void * element, node_t * root, int(*compare)(void * elementA, void * elementB)) ;/* 刪除 BST 一個節點*/


node_t * findNode(node_t * root, int key); /* 找出 BST 符合鍵值的節點*/

void inOrder(node_t * root); /*列印出 BST 根據中序追蹤法每個節點內容*/

node_t * treeCopy(node_t *original); /*複製*/

int treeEqual(node_t * root1, node_t * root2); /*比較二個 BST 是否相同*/


#endif // BST_2_H_INCLUDED
