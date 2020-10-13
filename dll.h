#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
} dllNode_t;

void DLL_init(dllNode_t * head) //建構一個空的 list
{
    if(head == NULL)
        return;

    head = (dllNode_t*)malloc(sizeof(dllNode_t));   //分配節點空間

    head->next = NULL;
    head->prev = NULL;
}

int DLL_isEmpty(dllNode_t *head) // head 是否為空的list
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

dllNode_t * DLL_next_node(dllNode_t * node); //(下一個節點)

dllNode_t * DLL_prev_node(dllNode_t * node); //(上一個節點)

unsigned int DLL_num_nodes(dllNode *head) //計算List中有幾個node
{
    int countr=0; //紀錄節點數量

    while(head->next != NULL)
    {
        head = head->next;
        countr++;
    }
    return countr;
}

void DLL_add_before(dllNode_t * new_node, dllNode_t * head); //(將新node加入到head node的前一個)
{
    new_node->next = head->next;    //將新節點的next指向原來的第一個節點
    if(head->next != NULL)  //當鏈結只有一個節點
        head->next->prev = new_node;
    head->next = new_node;  //頭節點head的next指向新節點
    new_node->prev = head;  //新節點的prev指向頭節點head
}

void DLL_add_tail(dllNode_t * new_node, dllNode_t *head) //(將新node加入到head node的後一個)
{
    //找到鏈結尾端
    while(head->next != NULL)   //檢查節點下一個是不是尾端
        head = head->next;  //移動

    //將新節點插入尾端
    head->next = new_node;
    new_node->prev = head;
}

void DLL_delete(dllNode_t * node); //(從node所在的 Linked List 中刪除此點)
{
    if(head != NULL)    //鏈結有節點可刪除
    {
        if(node == head)    //刪除第一個節點
            head = head->next;
        else if(node->next == NULL)   //刪除最後一個節點
            node->next == NULL;
        else if(node->next != NULL && node->prev != NULL)  //刪除中間節點
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    else    //鏈結無節點可刪除
        return;

    //將節點歸還給記憶體
    free(node);
}

void DLL_concate(dllNode_t *firstList, dllNode_t * secondList); //(將secondList 串在firstList之後)
{
    firstList->next = secondList->prev;
    secondList->prev = firstList->next;
}

void DLL_reverse(dllNode_t *List)   //將鏈結頭尾指標互換
{
    dllNode_t *tail;
    while(head->next != NULL)   //找到尾端
    {
        head = head->next;
        if(head->next == NULL)
        {
            tail = head->next;
            return;
        }
    }
    dllNode_t *tmp; //交換頭跟尾的位子
    tmp = head;
    head = tail;
    tail = tmp;
}

void DLL_add_two_numbers(dllNode_t *firstList, dllNode_t * secondList, dllNode_t *thirdList)
{
    dllNode_t *head;

    //相加前先反轉
    DLL_reverse(*firstList);
    DLL_reverse(*secondList);
    DLL_reverse(*thirdList);

    int digit_ten = 0;

    while(firstList->head != NULL || secondList->head != NULL || digit_ten != 0)
    {
        int sum = 0;

        if(firstList->head != NULL && secondList->head != NULL)
            sum = firstList->head + firstList->head + digit_ten;    //兩鏈結相加並加上前一節點進位值
        else if(firstList->head == NULL )
            sum = secondList->head + digit_ten;
        else if(secondList->head == NULL)
            sum = secondList->head + digit_ten;
        else
            sum = digit_ten;

        int digit_one = sum % 10;   //取個位數
        digit_ten = sum / 10;   //取進位十位數

        thirdList->head = digit_one;    //將個位數結果記錄在第三個鏈結
        thirdList->head = thirdList->head->next;    //移至下一個節點
        firstList->head = firstList->head->next;    //移至下一個節點
        secondList->head = secondList->head->next;  //移至下一個節點
    }
    DLL_reverse(*thirdList);    //將儲存結果的鏈結反轉為正

    while(thirdList->head != NULL)
    {
        printf("%d", thirdList->head->data);
        thirdList->head = thirdList->head->next;
    }
    return ;
}
#endif // DLL_H_INCLUDED
