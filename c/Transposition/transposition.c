#include <stdio.h>
void PrintArrayMatrix(int **array, int row, int column);
int **ArrayTransposition(int **array, int row, int column);
int main()
{
    int m, n;
    printf("please input m n:\n");
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (int k = 1, i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = k++;
        }
    }
    printf("The Origin Array is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-5d ", a[i][j]);
        }
        printf("\n");
    }
    // PrintArrayMatrix((int **)a, m, n);
    // ArrayTransposition(a,m,n);
    {int temp;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    }
    printf("Now The Array is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-5d ", a[i][j]);
        }
        printf("\n");
    }
}
void PrintArrayMatrix(int **array, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%-5d\n", array[i][j]);
        }
    }
}

int **ArrayTransposition(int **array, int row, int column)
{
    int temp;
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}