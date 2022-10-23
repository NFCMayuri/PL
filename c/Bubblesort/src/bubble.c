#include "../include/BubbleSort.h"
int main()
{
    int a[] = {5, 10, 3, 7, 9, 6, 8, 1, 4, 2};
    int i;
    int size = sizeof(a) / sizeof(a[0]);
    printf("Before sorting:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
    BubbleSort(a, size);    
    printf("After sorting:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
// sort array[] and save to array[]
void BubbleSort(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void PrintIntArray(int *array, int length, char *interval) {
  for (int i = 0; i <= length - 1; i++) {
    printf("%d%s", *(array + i), interval);
  }
}