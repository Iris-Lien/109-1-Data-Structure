typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
} dllNode_t;

void DLL_init(dllNode_t * head) //建構一個空的 list
{
    head = (dllNode_t*)malloc(sizeof(dllNode_t));   //分配節點空間
    head->next = NULL;  //初始
    head->prev = NULL;  //初始
}

int DLL_isEmpty(dllNode_t *head) // head 是否為空的list
{
    if(head == NULL)    //如果head為NULL即為空的List
        return 1;
    else    //否則不為空的List
        return 0;
}

dllNode_t * DLL_next_node(dllNode_t * node); //(下一個節點)

dllNode_t * DLL_prev_node(dllNode_t * node); //(上一個節點)

unsigned int DLL_num_nodes(dllNode_t *head) //計算List中有幾個node
{
    int countr=0; //紀錄節點數量

    while(head->next != NULL)   //尋找尾端
    {
        head = head->next;  //將head指向下一個節點
        countr++;   //紀錄節點數量
    }
    return countr;  //回傳節點數量
}

void DLL_add_before(dllNode_t * new_node, dllNode_t * head) //(將新node加入到head的前一個)
{
    if(head!=NULL)  //鏈結有節點
    {
        new_node->next = head ;    //將新節點指向head
        head->prev = new_node;  //頭節點head的prev指向新節點
        head = new_node;  //head為新節點
    }
    else    //鏈結沒有節點
    {
        head = new_node;    //將head指向新的節點
    }
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

void DLL_delete(dllNode_t * node) //(從node所在的 Linked List 中刪除此點)
{
    dllNode_t * head;
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

dllNode_t DLL_concate(dllNode_t **firstList, dllNode_t * secondList) //(將secondList 串在firstList之後)
{
    dllNode_t *head1;   //紀錄L1的頭
    dllNode_t *head2;   //紀錄L2的頭
    dllNode_t *L1 = firstList;
    dllNode_t *L2 = secondList;
    dllNode_t *L3;

    if(L1 == NULL)  //如果L1為空,L3即L2
        L3 = L2;
    else if(L2 == NULL) //如果L2為空,L3即L1
        L3 = L1;
    else
    {
        while(head1->next != NULL) //尋找L1尾端
            head1 = head1->next;
        head1->next = head2;  //將L2接在L1之後
        head2->prev = head1;  //將L1接在L2之後
    }
}

struct dllNode_t *addTwoNumbers(dllNode_t *List1, dllNode_t * List2)
{
    int flag = 0, t = 0;
    dllNode_t* result=0;
    dllNode_t* head = result;
    dllNode_t* add;

    while(List1 || List2 || flag)
    {
        if(List1)
            t = List1->data;    //如果List1非空將data存入t
        else
            t = 0;

        if(List2)
            t = List2->data;    //如果List2非空將data存入t
        else
            t = 0;

        t += flag;  //flag表示進位

        if(t > 9)   //判斷和是否大於10
        {
            add->data = t-10;   //減掉10之後為個位數存入data
            flag = 1;   //進位1
        }
        else
        {
            add->data = t;
            flag = 0;
        }

        add->next = NULL;   //接地

        if(List1)
            List1 = List1->next;    //如果List1非空尋找下一個節點
        if(List2)
            List2 = List2->next;    //如果List2非空尋找下一個節點

        result->next = add; //指向下一個result
        result = add;   //將結果存入result
    }
    result = head->next;
    free(head); //歸還記憶體
    printf("%p",&result);   //輸出結果
}
