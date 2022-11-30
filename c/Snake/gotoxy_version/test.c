#include "GlobalVar.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gotoxy(int y, int x)
{
    printf("%c[%d;%df", 0x1B, ((y) + 1), ((x) + 1));
}
int main()
{
    for (i = 0; i < (WIDTH)*2; i++)
        printf("_");
    printf("\n");
    for (i = 0; i < (HEIGHT); i++)
    {
        for (j = 0; j < (WIDTH); j++)
        {
            if (a[i][j] == 0)
                printf("_|");
            else
                printf("%c|", a[i][j]);
        }
        printf("\n");
    }
    while (1)
    {
        gotoxy(3, i++);
        printf("%d", i);
        gotoxy(HEIGHT + 7, 40);
    }
}
