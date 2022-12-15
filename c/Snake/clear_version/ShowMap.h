#ifndef _SHWOMAP_H
#define _SHWOMAP_H
#include "Clear.h"
#include "GlobalVar.h"
#include <stdio.h>
#define ShowMap()                                                              \
    {                                                                          \
        Clear();                                                               \
        printf("Your Score is:%d\n", n - 3);                                   \
        for (i = 0; i < (WIDTH)*2; i++)                                        \
            printf("_");                                                       \
        printf("\n");                                                          \
        for (i = 0; i < (HEIGHT); i++)                                         \
        {                                                                      \
            for (j = 0; j < (WIDTH); j++)                                      \
            {                                                                  \
                if (a[i][j] == 0)                                              \
                    printf("_|");                                              \
                else                                                           \
                    printf("%c|", a[i][j]);                                    \
            }                                                                  \
            printf("\n");                                                      \
        }                                                                      \
        printf("\nw,s,a,d->Up Down Left Right;\nj,k->Speed "                   \
               "Up/Down;\nESC: Exit\n");                                       \
    }

#endif