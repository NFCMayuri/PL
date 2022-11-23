#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int input1, input2;
    int i;
    printf("Please input the number of student:\n");
    scanf("%d", &input1);
    printf("choose n person in the students randomly\nplease input n:\n");
    scanf("%d", &input2);

    srand((unsigned int)time(NULL));
    int array[input2];
    int j;
    for (i = 0; i < input2; i++)
    {
        array[i] = rand() % input1 + 1;
        for (j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                i--;
            }
        }
    }
    i--;
    do
    {
        printf("array[%d]=%d\n", i, array[i]);
        i--;
    } while (i + 1);
}
