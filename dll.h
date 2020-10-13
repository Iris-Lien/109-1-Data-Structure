#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
} dllNode_t;

void DLL_init(dllNode_t * head) //�غc�@�ӪŪ� list
{
    if(head == NULL)
        return;

    head = (dllNode_t*)malloc(sizeof(dllNode_t));   //���t�`�I�Ŷ�

    head->next = NULL;
    head->prev = NULL;
}

int DLL_isEmpty(dllNode_t *head) // head �O�_���Ū�list
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

dllNode_t * DLL_next_node(dllNode_t * node); //(�U�@�Ӹ`�I)

dllNode_t * DLL_prev_node(dllNode_t * node); //(�W�@�Ӹ`�I)

unsigned int DLL_num_nodes(dllNode *head) //�p��List�����X��node
{
    int countr=0; //�����`�I�ƶq

    while(head->next != NULL)
    {
        head = head->next;
        countr++;
    }
    return countr;
}

void DLL_add_before(dllNode_t * new_node, dllNode_t * head); //(�N�snode�[�J��head node���e�@��)
{
    new_node->next = head->next;    //�N�s�`�I��next���V��Ӫ��Ĥ@�Ӹ`�I
    if(head->next != NULL)  //���쵲�u���@�Ӹ`�I
        head->next->prev = new_node;
    head->next = new_node;  //�Y�`�Ihead��next���V�s�`�I
    new_node->prev = head;  //�s�`�I��prev���V�Y�`�Ihead
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

void DLL_delete(dllNode_t * node); //(�qnode�Ҧb�� Linked List ���R�����I)
{
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

void DLL_concate(dllNode_t *firstList, dllNode_t * secondList); //(�NsecondList ��bfirstList����)
{
    firstList->next = secondList->prev;
    secondList->prev = firstList->next;
}

void DLL_reverse(dllNode_t *List)   //�N�쵲�Y�����Ф���
{
    dllNode_t *tail;
    while(head->next != NULL)   //������
    {
        head = head->next;
        if(head->next == NULL)
        {
            tail = head->next;
            return;
        }
    }
    dllNode_t *tmp; //�洫�Y�������l
    tmp = head;
    head = tail;
    tail = tmp;
}

void DLL_add_two_numbers(dllNode_t *firstList, dllNode_t * secondList, dllNode_t *thirdList)
{
    dllNode_t *head;

    //�ۥ[�e������
    DLL_reverse(*firstList);
    DLL_reverse(*secondList);
    DLL_reverse(*thirdList);

    int digit_ten = 0;

    while(firstList->head != NULL || secondList->head != NULL || digit_ten != 0)
    {
        int sum = 0;

        if(firstList->head != NULL && secondList->head != NULL)
            sum = firstList->head + firstList->head + digit_ten;    //���쵲�ۥ[�å[�W�e�@�`�I�i���
        else if(firstList->head == NULL )
            sum = secondList->head + digit_ten;
        else if(secondList->head == NULL)
            sum = secondList->head + digit_ten;
        else
            sum = digit_ten;

        int digit_one = sum % 10;   //���Ӧ��
        digit_ten = sum / 10;   //���i��Q���

        thirdList->head = digit_one;    //�N�Ӧ�Ƶ��G�O���b�ĤT���쵲
        thirdList->head = thirdList->head->next;    //���ܤU�@�Ӹ`�I
        firstList->head = firstList->head->next;    //���ܤU�@�Ӹ`�I
        secondList->head = secondList->head->next;  //���ܤU�@�Ӹ`�I
    }
    DLL_reverse(*thirdList);    //�N�x�s���G���쵲���ର��

    while(thirdList->head != NULL)
    {
        printf("%d", thirdList->head->data);
        thirdList->head = thirdList->head->next;
    }
    return ;
}
#endif // DLL_H_INCLUDED
