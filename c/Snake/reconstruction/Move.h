#ifndef _MOVE_H
#define _MOVE_H
#include "GetXYFromArrays.h"
#include "GlobalVar.h"
#include "GotoXY.h"
#define moveBody()                                                             \
    {                                                                          \
        *p[n] = 0;                                                             \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[n], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[n], WIDTH) * 2), "_")                       \
        for (i = n; i > 0; i--)                                                \
        {                                                                      \
            p[i] = p[i - 1];                                                   \
            /* per part goes to the address of the next part of body*/         \
        }                                                                      \
        *p[0] = BODY;                                                          \
        /* The First part of snake body come to snake head*/                   \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[0], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[0], WIDTH) * 2), BODY_STRING)               \
    }

#define moveRight()                                                            \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] + 1; /* Move snake head */                                 \
        *p[0] = HEAD;                                                          \
        /* change the char of new head(new address)'s shape to HEAD */         \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[0], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[0], WIDTH) * 2), HEAD_STRING)               \
    }
#define moveLeft()                                                             \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] - 1;                                                       \
        *p[0] = HEAD;                                                          \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[0], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[0], WIDTH) * 2), HEAD_STRING)               \
    }
#define moveDown()                                                             \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] + WIDTH;                                                   \
        *p[0] = HEAD;                                                          \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[0], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[0], WIDTH) * 2), HEAD_STRING)               \
    }
#define moveUp()                                                               \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] - WIDTH;                                                   \
        *p[0] = HEAD;                                                          \
        PRINT_STRING_XY((GETX_CHAR(a[0], p[0], WIDTH) + 2),                            \
                (GETY_CHAR(a[0], p[0], WIDTH) * 2), HEAD_STRING)               \
    }
#endif