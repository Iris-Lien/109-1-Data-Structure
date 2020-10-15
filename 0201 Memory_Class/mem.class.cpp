#include <iostream>
#include <cstdlib>

using namespace std;

class Memory
{
public:
    static int **allocArray(int m, int n)
    {
        int **arr;
        arr = new int*[m];
        for(int i=0;i<n;i++)
            arr[i] = new int[n];
    }
};

int main()
{
    int **array;
    array = Memory::allocArray(5, 10);
    int j, k;
    for(j = 0; j < 5; j ++)
        for(k = 0; k < 10; k ++)
            array[j][k] = j * 10 + k;
    for(j = 0; j < 5; j ++)
        for(k = 0; k < 10; k ++)
            cout<<array[j][k]<<" ";
}
