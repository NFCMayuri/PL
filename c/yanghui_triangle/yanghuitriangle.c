#include <stdio.h>
int main()
{
    int n;
    printf("please input a num:\n");
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        a[i][i] = 1;
        a[i][0] = 1;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    printf("array is :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // print_array(a, n, n);
    return 0;
}

void print_array(int **n, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d", n[i][j]);
        }
    }
}