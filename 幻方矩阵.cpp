#include<stdio.h>
#define MAX 3 
int Fun(int a[MAX][MAX])
{
    int s1, s2, sum;
    int i, j;

    sum = 0;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            sum += a[i][j];

    sum /= MAX;

    for (i = 0; i < MAX; i++)
    {
        s1 = s2 = 0;
        for (j = 0; j < MAX; j++) //判断每一行每一列
        {
            s1 += a[i][j];
            s2 += a[j][i];
        }
        if (s1 != sum || s2 != sum)
        {
            return 0;
        }
    }
    s1 = s2 = 0;
    for (i = 0; i < MAX; i++) //判断每一撇：主对角线
    {
        s1 += a[i][i];
        s2 += a[i][MAX - i - 1];
    }
    if (s1 != sum || s2 != sum)
        return 0;
    return 1;
}
int main()
{
    int i, j;
    int a[MAX][MAX];
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d ", &a[i][j]);


    if (Fun(a) == 1)
    {
        printf("It is a magic square!\n");
    }
    else
        printf("It is not a magic square!\n");

    return 0;
}
