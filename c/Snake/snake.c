// https://zxbcw.cn/post/218247/

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#include "pthread.h"
#include <conio.h>
#include <windows.h>

#elif defined(__linux__) || defined(__gnu_linux__)
#include <pthread.h>
#include <unistd.h>
#elif defined(__APPLE__)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 40
#define Y 20

// char HEAD = '@'; // The shape of snake head
// char BODY = 'O'; // The shape of snake body
#define HEAD '@'                           // The shape of snake head
#define BODY 'O'                           // The shape of snake body
char a[Y][X] = {{BODY, BODY, BODY, HEAD}}; // The initial char is 0
char *p[Y * X] = {&a[0][3], &a[0][2], &a[0][1],
                  &a[0][0]}; // p[0] stand for snake head

int n = 3; // The length of snake body (without head)
int i, j;
int direction = 1; // 1.right;2.up;3.left;4.down;-1.exit
int delay = 200;   // delay 0.2s(200ms)
#define moveBody()                                                             \
    {                                                                          \
        *p[n] = 0;                                                             \
        for (i = n; i > 0; i--)                                                \
        {                                                                      \
            p[i] = p[i - 1]; /* per part goes to the address of the next part  \
                                ofbody*/                                       \
        }                                                                      \
        *p[0] = BODY; /* The First part of snake body come to snake head*/     \
    }
void moveRight()
{
    moveBody();
    p[0] = p[0] + 1; // Move snake head
    *p[0] = HEAD;    // change the char of new head(new address)'s shape to HEAD
}
void moveLeft()
{
    moveBody();
    p[0] = p[0] - 1;
    *p[0] = HEAD;
}
void moveDown()
{
    moveBody();
    p[0] = p[0] + X;
    *p[0] = HEAD;
}
void moveUp()
{
    moveBody();
    p[0] = p[0] - X;
    *p[0] = HEAD;
}

void show()
{
    system("clear");
    for (i = 0; i < X; i++)
        printf("_");
    printf("\n");
    for (i = 0; i < Y; i++)
    {
        // printf("|");
        for (j = 0; j < X; j++)
        {
            printf("%c", (a[i][j] == 0) ? ' ' : a[i][j]);
        }
        // printf("|");
        printf("\n");
    }
    for (i = 0; i < X; i++)
        printf("-");
    printf("\nw,s,a,d->Up Down Left Right;j,k->Speed Up/Down;ESC: Exit\n");
}

void randomApple() // Random
{
    srand(time(NULL));
    do
    {
        i = rand() % Y;
        j = rand() % X;
        // if random location is 0 ->*;else find again and again
    } while (a[i][j] != 0);
    a[i][j] = '*';
}

void canEat()
{
    switch (direction)
    {
    // Right
    case 1: {
        if (*(p[0] + 1) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            randomApple();
        }
        break;
    }
    // Up
    case 2: {
        if (*(p[0] - X) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            randomApple();
        }
        break;
    }
    // Left
    case 3: {
        if (*(p[0] - 1) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            randomApple();
        }
        break;
    }
    // Down
    case 4: {
        if (*(p[0] + X) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            randomApple();
        }
        break;
    }
    }
}

void isFail()
{
    if (p[0] < &a[0][0] ||
        p[0] > &a[Y - 1][X - 1]) // snake is not in the matrix
    {
        printf("fail!\n");
        direction = -1;
    }
    else
    {
        switch (direction)
        {
        // Right
        case 1: {
            for (i = n; i > 0; i--)
            {
                if ((p[0] + 1) == p[i]) // Right of the head is body
                {
                    printf("fail!\n");
                    direction = -1;
                }
            }
            break;
        }
        // Up
        case 2: {
            for (i = n; i > 0; i--)
            {
                if ((p[0] - X) == p[i]) // Up of the head is body
                {
                    printf("fail!\n");
                    direction = -1;
                }
            }
            break;
        }
        // Left
        case 3: {
            for (i = n; i > 0; i--)
            {
                if ((p[0] - 1) == p[i]) // Left of the head is body
                {
                    printf("fail!\n");
                    direction = -1;
                }
            }
            break;
        }
        // Down
        case 4: {
            for (i = n; i > 0; i--)
            {
                if ((p[0] + X) == p[i]) // Down of the head is body
                {
                    printf("fail!\n");
                    direction = -1;
                }
            }
            break;
        }
        }
    }
}

void *key(void *arg) // Direction Control：w,s,a,d-->Up Down Left Right
{
    char k;
    while (1)
    {
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        k = _getch();
#elif defined(__linux__) || defined(__gnu_linux__)
        k = getchar();
#elif defined(__APPLE__)
#endif
        switch (k)
        {
        case 'w': // Up
        {
            if (direction != 4)
                direction = 2;
            break;
        }
        case 's': // Down
        {
            if (direction != 2)
                direction = 4;
            break;
        }
        case 'a': // Left
        {
            if (direction != 1)
                direction = 3;
            break;
        }
        case 'd': // Right
        {
            if (direction != 3)
                direction = 1;
            break;
        }
        case 'j': // SpeedUp
        {
            delay = delay * 4 / 5;
            break;
        }
        case 'k': // SpeedDown
        {
            delay = delay * 5 / 4;
            break;
        }
        case 27: // ESC
        {
            printf("Exit！\n");
            direction = -1;
            break;
        }
        }
    }
}

int main()
{
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#elif defined(__linux__) || defined(__gnu_linux__)
    // close lined buffer of input for no enter to capture input
    system("stty -icanon");
#elif defined(__APPLE__)
#endif
    pthread_t pid;
    pthread_create(&pid, NULL, key, NULL); // Create pthread to capture input
    randomApple();
    while (1)
    {
        show();

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        Sleep(delay);
#elif defined(__linux__) || defined(__gnu_linux__)
        usleep(delay * 1000);
#elif defined(__APPLE__)
#endif

        isFail();          // Judge if will eat self
        canEat();          // Judge if will eat *
        switch (direction) // choose which direction to move
        {
        case 1: // Right
        {
            moveRight();
            break;
        }
        case 2: // Up
        {
            moveUp();
            break;
        }
        case 3: // Left
        {
            moveLeft();
            break;
        }
        case 4: // Down
        {
            moveDown();
            break;
        }
        case -1: // Exit
        {
            pthread_cancel(pid); // Close pthread
            return -1;
            break;
        }
        }
    }

    return 0;
}