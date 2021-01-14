#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int insert(int root[20][4], int node)
{
    int f = 0, index = 0;
    while(root[index][0] != -1)
        index ++;
    if(index >= 20)
        return -1;
    if(index == 0)
    {
        root[0][0] = 1;
        root[0][1] = node;
        return 1;
    }
    else
    {
        root[index][0] = 1;
        root[index][1] = node;
        while(1)
        {
            if(root[f][1] < node)
            {
                if(root[f][3] == -1)
                {
                    root[f][3] = index;
                    return 1;
                }
                else
                {
                    f = root[f][3];
                }
            }
            else
            {
                if(root[f][2] == -1)
                {
                    root[f][2] = index;
                    return 1;
                }
                else
                {
                    f = root[f][2];
                }
            }
        }
    }

}

void inorder(int root[20][4], int index)
{
    if(root[index][2] != -1)
        inorder(root, (root[index][2]) );
    printf("%d ", root[index][1]);
    if(root[index][3] != -1)
        inorder(root, (root[index][3]) );
}

void preorder(int root[20][4], int index)
{
    printf("%d ", root[index][1]);
    if(root[index][2] != -1)
        preorder(root, (root[index][2]) );
    if(root[index][3] != -1)
        preorder(root, (root[index][3]) );
}

void postorder(int root[20][4], int index)
{
    if(root[index][2] != -1)
        postorder(root, (root[index][2]) );
    if(root[index][3] != -1)
        postorder(root, (root[index][3]) );
    printf("%d ", root[index][1]);

}

void levelorder(int root[20][4])
{
    int queue[10] = {-1};   //queue初始化
    int index = 0;
    int current = 0;    //紀錄queue正在計算的位置
    //int head = 0;
    int root_i = 0;
    if(root[0][1] == -1)
        return;
    else
    {
        while(root[index][0] != -1 && current<10)
        {
            if(index == 0)
            {
                queue[index] = root[root_i][1];
                printf("%d ", queue[index]);  //將頭先存入queue[0]
                index++;
            }
            for(int j = 0 ; j < 10 ; j++)
            {
                if(queue[current] == (root[j][1]))
                {
                    root_i = j;
                    break;
                }
            }
            if(root[current][2] != -1)  //有左子樹
            {
                int left = root[current][2];
                //printf("left: %d\n",left);
                queue[index] = root[left][1];
                printf("%d ", queue[index]);
                index++;
            }
            if(root[current][3] != -1)  //有右子樹
            {
                int right = root[current][3];
                //printf("right: %d\n",right);
                queue[index] = root[right][1];
                printf("%d ", queue[index]);
                index++;
            }
            current++;
        }
    }
}

int main()
{
    int tree[20][4];
    int j, k, node;
    srand(time(NULL));

    for(j = 0; j < 20; j ++)
        for(k = 0; k < 4; k ++)
            tree[j][k] = -1;

    for(j = 0; j < 10; j ++)
    {
        node = rand() % 100;
        insert(tree, node);
    }

    inorder(tree, 0);
    printf("\n");
    preorder(tree, 0);
    printf("\n");
    postorder(tree, 0);
    printf("\n");
    levelorder(tree);
    printf("\n");
}
