#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void bubbleSort(int *array, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void selectionSort(int *array, int n)
{
    int i, j, min;
    for ( i = 0 ; i < n-1 ; i ++ )
    {
        min = i ;
        for ( j = i + 1 ; j < n ; j ++ )
        {
            if ( array[min] > array[j])
                min = j ;
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}
void insertionSort(int *array, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int key = array[i];
        j = i - 1;
        while (key < array[j] && j >= 0)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
int main()
{
    int array[SIZE];
    int j, k;
    srand(time(NULL));
    for(j = 0; j < SIZE; j ++)
        array[j] = rand();

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");

    bubbleSort(array, SIZE);

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");

    for(j = 0; j < SIZE; j ++)
        array[j] = rand();

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");

    insertionSort(array, SIZE);

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");

    for(j = 0; j < SIZE; j ++)
        array[j] = rand();

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");

    selectionSort(array, SIZE);

    for(j = 0; j < SIZE; j ++)
        printf("%d ", array[j]);
    printf("\n");
}
