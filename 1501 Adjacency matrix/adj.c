#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Vertex
{
	struct Vertex *edgeList[100];
	int edgeCount;
	int id;
};

void create(struct Vertex v[10], int m[10][10])
{
    int j, k;
    for (j=0;j<10;j++)
    {
        for(k=0;k<10;k++)
        {
            if(m[j][k]==1)
            {
                v[j].edgeList[v[j].edgeCount] = &v[k];
                v[j].edgeCount++;
            }
        }
    }
}

void print(struct Vertex v[10])
{
	int j, k;
	for(j = 0;j < 10;j ++)
	{
		printf("%d :", v[j].id);
		for(k = 0;k < v[j].edgeCount;k ++)
		{
			printf(" %d",v[j].edgeList[k]->id);
		}
		printf("\n");
	}
}

int main()
{
	struct Vertex v[10];
	int j, k, i, l;
	int map[10][10];

	srand(time(NULL));
	//產生點
	for(j = 0;j < 10;j ++)
	{
		v[j].id = j + 1;
		v[j].edgeCount = 0;
	}

	//建立 adjacency matrix
	for(j = 0;j < 10;j ++)
	{
		for(k = 0;k < 10;k ++)
		{
			if(rand() % 10 > 3)
				map[j][k] = 1;
			else
				map[j][k] = 0;
		}
	}

	//建圖
	create(v, map);

	print(v);
}
