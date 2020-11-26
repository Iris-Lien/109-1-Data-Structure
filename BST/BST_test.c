#include<stdio.h>
#include<stdlib.h>
#include "BST_2.h"

/*
    Binary Search Tree(簡稱BST)有以下特性:
    1. 左邊子樹的所有節點都比root來的小
    2. 右邊子樹的所有節點都比root來的大
*/

/*struct node
{
    int data;   //節點資料
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
    /*若root不為空，尋找位子插入節點*/
    struct MyNode* r0 = (struct MyNode *)root;
    if(r0)
    {
        int result = compare(element,(void *)r0); /*紀錄比大小結果，大為1，小為0*/
        /* 判斷想要插入的節點在右或左*/
        if(result == 1) /*要插入的節點較大,插入至右邊*/
            r0->links->right = insertNode(element,r0->links->right, compare);
        else if(result == -1)   /*要插入的節點較小,插入至左邊*/
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

node_t * findMinNode(node_t * root) /*找出 BST 中鍵值最小的節點*/
{
    node_t * current = root;
    struct MyNode* c0 = (struct MyNode *)current;
    /* 尋找最左的節點即為最小值 */
    while (c0 && c0->links->left != NULL)
        c0 = c0->links->left;

    return (node_t *)c0;
}

node_t * findMaxNode(node_t * root) /*找出 BST 中鍵值最大的節點*/
{
    node_t * current = root;
    struct MyNode* c0 = (struct MyNode *)current;
    /* 尋找最右的節點即為最大值 */
    while (c0 && c0->links->right != NULL)
        c0 = c0->links->right;

    return (node_t *)c0;
}

node_t * deleteNode(void * element, node_t * root, int(*compare)(void * elementA, void * elementB)) /* 刪除 BST 一個節點*/
{
    /* 確認想要刪除的節點是否存在BST中*/
    int *e0 = element;
    struct MyNode* r0 = (struct MyNode *)root;
    node_t * temp;
    struct MyNode* t0 = (struct MyNode *)temp;

    if (r0 == NULL)
        return NULL;

    int ret = compare(element, &(r0->data));

    if (ret == 0)   //找到要刪除的節點
    {

        /* Case: 擁有一個小孩或沒有*/
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

        /* Case: 擁有兩個小孩->找替身(右子樹中最小值的節點)取代被刪除節點(root)的位子*/

        t0 = findMinNode(r0->links->right);    /*替身temp為右子樹中最小值的節點*/
        r0->data = t0->data;    /*複製替身的data至root的data*/
        r0->links->right = deleteNode(r0->links->right, t0->data, compare);  /*將替身刪除(再往下尋找是否有小孩)*/

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

node_t * findNode(node_t * root, int key) /* 找出 BST 符合鍵值的節點*/
{
    struct MyNode* r0 = (struct MyNode *)root;
    /* 先判斷root是否為空*/
    if(r0)
    {
        /* 找到符合鍵值的節點,回傳*/
        if(key == r0->data)
            return (node_t *)r0;

        /* 判斷是否比root大,是的話往右走,否則往左尋找*/
        if(key > r0->data)
            r0 = r0->links->right;
        else
            r0 = r0->links->left;
    }
    return NULL;
}

void inOrder(node_t * root) /*列印出 BST 根據中序追蹤法每個節點內容*/
{
    struct MyNode* r0 = (struct MyNode *)root;
    if(r0 != NULL)    /*檢查節點是否為NULL*/
    {
        inOrder(r0->links->left);    /*往左子樹尋訪*/
        printf(" %d ", r0->data); /*輸出data*/
        inOrder(r0->links->right);   /*往右子樹尋訪*/
    }
}

node_t * treeCopy(node_t *original) /*複製*/
{
    struct MyNode* original_t = (struct MyNode *)original;
    node_t *temp;
    struct MyNode* t0 = (struct MyNode *)temp;
    if(original_t)
    {
        t0 = (struct node*)malloc(sizeof(struct node));   /*配置temp的記憶體*/
        t0->links->left = treeCopy(original_t->links->left);  /*往左複製*/
        t0->links->right = treeCopy(original_t->links->right);    /*往右複製*/
        t0->data = original_t->data;    /*複製data*/
        return (node_t *)t0;
    }
    return NULL;
}

int treeEqual(node_t * root1, node_t * root2) /*比較二個 BST 是否相同*/
{
    /*如果二元樹root1和root2相同回傳1;
      否則回傳0*/

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

