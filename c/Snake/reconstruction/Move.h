#ifndef _MOVE_H
#define _MOVE_H
#include "GetXYFromArrays.h"
#include "globalvar.h"
#include "gotoxy.h"
#define moveBody()                                                             \
    {                                                                          \
        *p[n] = 0;                                                             \
        for (i = n; i > 0; i--)                                                \
        {                                                                      \
            p[i] = p[i - 1];                                                   \
            /* per part goes to the address of the next part of body*/         \
        }                                                                      \
        *p[0] = BODY;                                                          \
        /* The First part of snake body come to snake head*/                   \
    }

#define moveRight()                                                            \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] + 1; /* Move snake head */                                 \
        *p[0] = HEAD; /* change the char of new head(new address)'s shape to   \
                         HEAD */                                               \
    }
#define moveLeft()                                                             \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] - 1;                                                       \
        *p[0] = HEAD;                                                          \
    }
#define moveDown()                                                             \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] + WIDTH;                                                   \
        *p[0] = HEAD;                                                          \
    }
#define moveUp()                                                               \
    {                                                                          \
        moveBody();                                                            \
        p[0] = p[0] - WIDTH;                                                   \
        *p[0] = HEAD;                                                          \
    }
#endif