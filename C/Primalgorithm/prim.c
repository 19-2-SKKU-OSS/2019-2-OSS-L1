/*
 * C Program to find MST(Minimum Spanning Tree) using 
 * Prim's Algorithm
 */
#include <stdio.h>

struct node
{
    int fr, to, cost;
}p[6];
int c = 0, temp1 = 0, temp = 0;
void prims(int *a, int b[][7], int i, int j)
{
    a[i] = 1;
    while (c < 6)
    {
        int min = 999;
        for (int i = 0; i < 7; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < 7; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;       
        b[temp][temp1] = b[temp1][temp]=1000;
    }
    for (int k = 0; k < 6; k++)
    {
	    printf("source node : %d\n",p[k].fr);
	    printf("destination node : %d\n",p[k].to);
	    printf("weight of node : %d\n",p[k].cost);
    }
}
int main()
{
    int a[7];
    for (int i = 0; i < 7; i++)
    {
        a[i] = 0;
    }
    int b[7][7];
    for (int i = 0; i < 7; i++)
    {
	    printf("enter values for %d row\n",i+1);
        for (int j = 0; j < 7; j++)
        {
		scanf("%d",&b[i][j]);
        }
    }
    prims(a, b, 0, 0);

}
