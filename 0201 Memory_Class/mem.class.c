#include <stdio.h>

void allocArray(int ***p, int m, int n)
{
    int **arr = (int **)malloc( (m+10) * sizeof(int *));
    for (int i = 0; i < m; i++)
        arr[i] = (int *)malloc( (n+10) * sizeof(int ));
    *p =arr;
}

int main()
{
    int **array, *a;
    int j, k;
    allocArray(&array, 5, 10);
    for(j = 0; j < 5; j ++)
        for(k = 0; k < 10; k ++)
            array[j][k] = j * 10 + k;
    for(j = 0; j < 5; j ++)
        for(k = 0; k < 10; k ++)
            printf("%p ", &(array[j][k]));
}
