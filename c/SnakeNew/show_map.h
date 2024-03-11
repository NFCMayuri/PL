#ifndef _SHWOMAP_H
#define _SHWOMAP_H
#include "clear.h"
#include "global_var.h"
#include <stdio.h>
inline void ShowMap()
{
    clear_screen();
    printf("Your Score is:%d\n", n - 3);
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
    printf("\nw,s,a,d->Up Down Left Right;\nj,k->Speed "
           "Up/Down;\nESC: Exit\n");
}
void ShowMap();
#endif /* _SHWOMAP_H */
