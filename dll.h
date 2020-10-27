typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
} dllNode_t;

void DLL_init(dllNode_t * head) //�غc�@�ӪŪ� list
{
    head = (dllNode_t*)malloc(sizeof(dllNode_t));   //���t�`�I�Ŷ�
    head->next = NULL;  //��l
    head->prev = NULL;  //��l
}

int DLL_isEmpty(dllNode_t *head) // head �O�_���Ū�list
{
    if(head == NULL)    //�p�Ghead��NULL�Y���Ū�List
        return 1;
    else    //�_�h�����Ū�List
        return 0;
}

dllNode_t * DLL_next_node(dllNode_t * node); //(�U�@�Ӹ`�I)

dllNode_t * DLL_prev_node(dllNode_t * node); //(�W�@�Ӹ`�I)

unsigned int DLL_num_nodes(dllNode_t *head) //�p��List�����X��node
{
    int countr=0; //�����`�I�ƶq

    while(head->next != NULL)   //�M�����
    {
        head = head->next;  //�Nhead���V�U�@�Ӹ`�I
        countr++;   //�����`�I�ƶq
    }
    return countr;  //�^�Ǹ`�I�ƶq
}

void DLL_add_before(dllNode_t * new_node, dllNode_t * head) //(�N�snode�[�J��head���e�@��)
{
    if(head!=NULL)  //�쵲���`�I
    {
        new_node->next = head ;    //�N�s�`�I���Vhead
        head->prev = new_node;  //�Y�`�Ihead��prev���V�s�`�I
        head = new_node;  //head���s�`�I
    }
    else    //�쵲�S���`�I
    {
        head = new_node;    //�Nhead���V�s���`�I
    }
}

void DLL_add_tail(dllNode_t * new_node, dllNode_t *head) //(�N�snode�[�J��head node����@��)
{
    //����쵲����
    while(head->next != NULL)   //�ˬd�`�I�U�@�ӬO���O����
        head = head->next;  //����

    //�N�s�`�I���J����
    head->next = new_node;
    new_node->prev = head;
}

void DLL_delete(dllNode_t * node) //(�qnode�Ҧb�� Linked List ���R�����I)
{
    dllNode_t * head;
    if(head != NULL)    //�쵲���`�I�i�R��
    {
        if(node == head)    //�R���Ĥ@�Ӹ`�I
            head = head->next;
        else if(node->next == NULL)   //�R���̫�@�Ӹ`�I
            node->next == NULL;
        else if(node->next != NULL && node->prev != NULL)  //�R�������`�I
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    else    //�쵲�L�`�I�i�R��
        return;

    //�N�`�I�k�ٵ��O����
    free(node);
}

dllNode_t DLL_concate(dllNode_t **firstList, dllNode_t * secondList) //(�NsecondList ��bfirstList����)
{
    dllNode_t *head1;   //����L1���Y
    dllNode_t *head2;   //����L2���Y
    dllNode_t *L1 = firstList;
    dllNode_t *L2 = secondList;
    dllNode_t *L3;

    if(L1 == NULL)  //�p�GL1����,L3�YL2
        L3 = L2;
    else if(L2 == NULL) //�p�GL2����,L3�YL1
        L3 = L1;
    else
    {
        while(head1->next != NULL) //�M��L1����
            head1 = head1->next;
        head1->next = head2;  //�NL2���bL1����
        head2->prev = head1;  //�NL1���bL2����
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
            t = List1->data;    //�p�GList1�D�űNdata�s�Jt
        else
            t = 0;

        if(List2)
            t = List2->data;    //�p�GList2�D�űNdata�s�Jt
        else
            t = 0;

        t += flag;  //flag��ܶi��

        if(t > 9)   //�P�_�M�O�_�j��10
        {
            add->data = t-10;   //�10���ᬰ�Ӧ�Ʀs�Jdata
            flag = 1;   //�i��1
        }
        else
        {
            add->data = t;
            flag = 0;
        }

        add->next = NULL;   //���a

        if(List1)
            List1 = List1->next;    //�p�GList1�D�ŴM��U�@�Ӹ`�I
        if(List2)
            List2 = List2->next;    //�p�GList2�D�ŴM��U�@�Ӹ`�I

        result->next = add; //���V�U�@��result
        result = add;   //�N���G�s�Jresult
    }
    result = head->next;
    free(head); //�k�ٰO����
    printf("%p",&result);   //��X���G
}
