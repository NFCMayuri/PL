#ifndef _MAPINIT_H
#define _MAPINIT_H
#include <stdio.h>
#define mapInit()                                                              \
    {                                                                          \
        system("clear");                                                       \
        printf("Your Score is:\n"); /* (0,13) */                               \
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