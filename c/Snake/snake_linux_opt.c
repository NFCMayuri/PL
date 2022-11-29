// https://zxbcw.cn/post/218247/

#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// char HEAD = '@'; // The shape of snake head
// char BODY = 'O'; // The shape of snake body
#define HEAD '@'                                    // The shape of snake head
#define BODY 'O'                                    // The shape of snake body
char a[HEIGHT][WIDTH] = {{BODY, BODY, BODY, HEAD}}; // The initial char is 0
char *p[HEIGHT * WIDTH] = {&a[0][3], &a[0][2], &a[0][1],
                           &a[0][0]}; // p[0] stand for snake head

int n = 3; // The length of snake body (without head)
int i, j;
int direction = 1;      // 1.right;2.up;3.left;4.down;-1.exit
int delay = 200 * 1000; // delay 0.2s(200ms)
_Bool isPause = 0;
#define gotoxy(y, x) printf("%c[%ld;%ldf", 0x1B, ((y) + 1), ((x) + 1))

#define moveBody()                                                             \
    {                                                                          \
        gotoxy((((p[0] - a[0]) / WIDTH) + 2), (2 * ((p[0] - a[0]) % WIDTH)));  \
        printf("%c", BODY);                                                    \
        /* change p[0] to body*/                                               \
        *p[n] = 0;                                                             \
        gotoxy((((p[n] - a[0]) / WIDTH) + 2), (2 * ((p[n] - a[0]) % WIDTH)));  \
        printf("%c", '_');                                                     \
        for (i = n; i > 0; i--)                                                \
        {                                                                      \
            p[i] = p[i - 1];                                                   \
            /* per part goes to the address of the next part of body*/         \
        }                                                                      \
        *p[0] = BODY;                                                          \
        /* The First part of snake body come to snake head*/                   \
    }

void moveRight()
{
    moveBody();
    p[0] = p[0] + 1;
    /* Move snake head */
    *p[0] = HEAD;
    /* change the char of new head(new address)'s shape to HEAD */
    gotoxy((((p[0] - a[0]) / WIDTH) + 2), (2 * ((p[0] - a[0]) % WIDTH)));
    printf("%c", HEAD);
    gotoxy(0, 62);
}
void moveLeft()
{
    moveBody();
    p[0] = p[0] - 1;
    *p[0] = HEAD;
    gotoxy((((p[0] - a[0]) / WIDTH) + 2), (2 * ((p[0] - a[0]) % WIDTH)));
    printf("%c", HEAD);
    gotoxy(0, 62);
}
void moveDown()
{
    moveBody();
    p[0] = p[0] + WIDTH;
    *p[0] = HEAD;
    gotoxy((((p[0] - a[0]) / WIDTH) + 2), (2 * ((p[0] - a[0]) % WIDTH)));
    printf("%c", HEAD);
    gotoxy(0, 62);
}
void moveUp()
{
    moveBody();
    p[0] = p[0] - WIDTH;
    *p[0] = HEAD;
    gotoxy((((p[0] - a[0]) / WIDTH) + 2), (2 * ((p[0] - a[0]) % WIDTH)));
    printf("%c", HEAD);
    gotoxy(0, 62);
}

void show()
{
    system("clear");
    printf("Your Score is:%d\n", n - 3);
    for (i = 0; i < WIDTH * 2; i++)
        printf("_");
    printf("\n");
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (a[i][j] == 0)
                printf("_|"); // □■
            else
                printf("%c|", a[i][j]);
        }
        printf("\n");
    }
    printf("\nw,s,a,d->Up Down Left Right;\nj,k->Speed Up/Down;\nESC: Exit\n");
}

_Bool randomApple() // Random
{
    srand(time(NULL));
    do
    {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
        // if random location is 0 ->*;else find again and again
    } while (a[i][j] != 0);
    a[i][j] = '*';
    gotoxy(i + 2, 2 * j);
    printf("*");
    gotoxy(0, 62);
    printf("Food is at (%02d,%02d)", i, j);
}

_Bool canEat()
{
    switch (direction)
    {
    // Right
    case 1: {
        if (*(p[0] + 1) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            return 1;
        }
        break;
    }
    // Up
    case 2: {
        if (*(p[0] - WIDTH) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            return 1;
        }
        break;
    }
    // Left
    case 3: {
        if (*(p[0] - 1) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            return 1;
        }
        break;
    }
    // Down
    case 4: {
        if (*(p[0] + WIDTH) == '*')
        {
            n++; // length++
            p[n] = p[n - 1];
            return 1;
        }
        break;
    }
    }
    return 0;
}

_Bool isFail()
{
    if (p[0] < &a[0][0] ||
        p[0] > &a[HEIGHT - 1][WIDTH - 1]) // snake is not in the matrix
    {
        gotoxy(27, 0);
        printf("fail!\nDon't hit the wall!\n");
        direction = -1;
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
                        gotoxy(27, 0);
                        printf("Fail!\nDon't eat your body!\n");
                        direction = -1;
                        return 1;
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
                        gotoxy(27, 0);
                        printf("fail!\nDon't hit the wall!\n");
                        direction = -1;
                        return 1;
                    }
                }
                break;
            }
        }
        // Left
        case 3: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] - 1) == p[i]) // Left of the head is body
                    {
                        gotoxy(27, 0);
                        printf("fail!\nDon't hit the wall!\n");
                        direction = -1;
                        return 1;
                    }
                }
                break;
            }
        }
        // Down
        case 4: {
            {
                for (i = n; i > 0; i--)
                {
                    if ((p[0] + WIDTH) == p[i]) // Down of the head is body
                    {
                        gotoxy(27, 0);
                        printf("fail!\nDon't hit the wall!\n");
                        direction = -1;
                        return 1;
                    }
                }
                break;
            }
        }
        }
    }
    return 0;
}

void *KeyMonitor(void *arg) // Direction Control：w,s,a,d-->Up Down Left Right
{
    char k;
    while (1)
    {

        k = getchar();
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
            gotoxy(27, 0);
            printf("Exit!\n");
            isPause = 0;
            direction = -1;
            pthread_exit(NULL);
            break;
        }
        case ' ': // Space
        {
            if (isPause)
            {
                gotoxy(27, 0);
                printf("Continue!\n");
            }
            else
            {
                gotoxy(27, 0);
                printf("Pause!\n");
            }
            isPause = !isPause;
            break;
        }
        }
    }
}

int main()
{
    system("stty -icanon");
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    // set pthread_attr to detached
    pthread_t tid;
    pthread_create(&tid, &attr, KeyMonitor,
                   NULL); // Create pthread to capture input
    show();
    randomApple();
    while (1)
    {
        do
        {
            usleep(delay);

        } while (isPause);
        isFail();          // Judge if will eat self
        switch (direction) // choose which direction to move
        {
        case 1: // Right
        {
            if (canEat())
            {
                moveRight();
                randomApple();
            }
            else
            {
                moveRight();
                gotoxy(0, 14);
                printf("%d", n - 3);
                gotoxy(0, 62);
            }
            break;
        }
        case 2: // Up
        {
            if (canEat())
            {
                moveUp();
                randomApple();
            }
            else
            {
                moveUp();
                gotoxy(0, 14);
                printf("%d", n - 3);
                gotoxy(0, 62);
            }
            break;
        }
        case 3: // Left
        {
            if (canEat())
            {
                moveLeft();
                randomApple();
            }
            else
            {
                moveLeft();
                gotoxy(0, 14);
                printf("%d", n - 3);
                gotoxy(0, 62);
            }
            break;
        }
        case 4: // Down
        {
            if (canEat())
            {
                moveDown();
                randomApple();
            }
            else
            {
                moveDown();
                gotoxy(0, 14);
                printf("%d", n - 3);
                gotoxy(0, 62);
            }
            break;
        }
        case -1: // Exit
        {
            gotoxy(27, 0);
            printf("Your Final Score is:%d\n", n - 3);
            return -1;
            break;
        }
        }
    }

    return 0;
}