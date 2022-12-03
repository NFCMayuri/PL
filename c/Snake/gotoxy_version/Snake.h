#ifndef _SNAKE_H
#define _SNAKE_H
#include "GetXYFromArrays.h"
#include "GlobalVar.h"
#include "GotoXY.h"
#include "KeyMonitor.h"
#include "Move.h"
#include "Random.h"
#include "ShowMap.h"
#include "Sleep.h"
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <handleapi.h>
#include <processthreadsapi.h>
#include <windows.h>
#elif defined(__linux__) || defined(__gnu_linux__)
#include <pthread.h>
#elif defined(__APPLE__)
#endif
#endif

/* Print String At (x,y) and make Cursor go to another place */
#define PRINT_STRING_XY(x, y, content)                                         \
    {                                                                          \
        gotoxy((x), (y));                                                      \
        printf("%s", (content));                                               \
        gotoxy(HEIGHT + 7, 40);                                                \
    }

/* Random Food */
#define RandomApple()                                                          \
    {                                                                          \
        srand(time(NULL));                                                     \
        do                                                                     \
        {                                                                      \
            i = rand() % HEIGHT;                                               \
            j = rand() % WIDTH;                                                \
            /* if random location is 0 ->*;else find again and again*/         \
        } while (a[i][j] != 0);                                                \
        a[i][j] = '*';                                                         \
        PRINT_STRING_XY(((GETX_CHAR((a[0]), (&a[i][j]), (WIDTH))) + 2),        \
                        ((GETY_CHAR((a[0]), (&a[i][j]), (WIDTH))) * 2), "*");  \
        gotoxy(0, 62);                                                         \
        printf("Food is at (%02d,%02d)", i, j);                                \
        gotoxy(HEIGHT + 7, 40);                                                \
    }

// exec when(before) moving
_Bool canEat()
{
    switch (direction)
    {
    // Right
    case 1: {
        if (*(p[0] + 1) == '*')
        {
            return 1;
        }
        break;
    }
    // Up
    case 2: {
        if (*(p[0] - WIDTH) == '*')
        {
            return 1;
        }
        break;
    }
    // Left
    case -1: {
        if (*(p[0] - 1) == '*')
        {
            return 1;
        }
        break;
    }
    // Down
    case -2: {
        if (*(p[0] + WIDTH) == '*')
        {
            return 1;
        }
        break;
    }
    }
    return 0;
}

// exec when(before) moving
int isFail()
{
    if (p[0] < &a[0][0] ||
        p[0] > &a[HEIGHT - 1][WIDTH - 1]) // snake is not in the matrix
    {
        direction = 0;
        return 1;
    }
    else
    {
        switch (direction)
        {
        // Right
        case 1: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] + 1) == p[i]) // Right of the head is body
                    {
                        direction = 0;
                        return 2;
                    }
                }
                break;
            }
        }
        // Up
        case 2: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] - WIDTH) == p[i]) // Up of the head is body
                    {
                        direction = 0;
                        return 2;
                    }
                }
                break;
            }
        }
        // Left
        case -1: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] - 1) == p[i]) // Left of the head is body
                    {
                        direction = 0;
                        return 2;
                    }
                }
                break;
            }
        }
        // Down
        case -2: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] + WIDTH) == p[i]) // Down of the head is body
                    {
                        gotoxy(27, 0);
                        direction = 0;
                        return 2;
                    }
                }
                break;
            }
        }
        }
    }
    return 0;
}

#define CheckInput()                                                           \
    if (direction != -directiontemp)                                           \
    {                                                                          \
        direction = directiontemp;                                             \
    }
