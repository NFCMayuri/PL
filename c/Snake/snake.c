// https://zxbcw.cn/post/218247/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define X 40
#define Y 20

// char HEAD = '@'; // 蛇头的形状
// char BODY = 'O'; // 蛇身的形状
#define HEAD '@'                                           // 蛇头的形状
#define BODY 'O'                                           // 蛇身的形状
char a[Y][X] = {{BODY, BODY, BODY, HEAD}};                 // 初始是0
char *p[Y * X] = {&a[0][3], &a[0][2], &a[0][1], &a[0][0]}; // p[0]表示蛇头位置

int n = 3; // 蛇身的长度（不带蛇头）
int i, j;
int direction = 1;  // 标志位：1.右；2.上；3.左；4.下；-1.退出
int delay = 200000; // 用于usleep，延时0.2秒
void moveBody()
{
    *p[n] = 0;
    for (i = n; i > 0; i--)
    {
        p[i] = p[i - 1]; // 每一节身体往上一节位置移动
    }
    *p[0] = BODY; // 身体到达原先的蛇头位置
}
void moveRight()
{
    moveBody();
    p[0] = p[0] + 1; // 蛇头移动
    *p[0] = HEAD;    // 新蛇头位置变成蛇头
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
    printf("\nw,s,a,d->上下左右；j,k->加减速;ESC退出\n");
}

void randomApple() // 随机数生成*
{
    srand(time(NULL));
    do
    {
        i = rand() % Y;
        j = rand() % X;
        // 随机位置的值为0，则产生*；否则继续找随机位置
    } while (a[i][j] != 0);
    a[i][j] = '*';
}

void canEat()
{
    if (direction == 1) // 右
    {
        if (*(p[0] + 1) == '*')
        {
            n++; // 长度增加
            p[n] = p[n - 1];
            randomApple(); // 随机数生成*
        }
    }
    if (direction == 2) // 上
    {
        if (*(p[0] - X) == '*')
        {
            n++; // 长度增加
            p[n] = p[n - 1];
            randomApple(); // 随机数生成*
        }
    }
    if (direction == 3) // 左
    {
        if (*(p[0] - 1) == '*')
        {
            n++; // 长度增加
            p[n] = p[n - 1];
            randomApple(); // 随机数生成*
        }
    }
    if (direction == 4) // 下
    {
        if (*(p[0] + X) == '*')
        {
            n++; // 长度增加
            p[n] = p[n - 1];
            randomApple(); // 随机数生成*
        }
    }
}

void isFail()
{
    if (p[0] < &a[0][0] || p[0] > &a[Y - 1][X - 1]) // 蛇头不在矩阵内
    {
        printf("fail!\n");
        direction = -1;
    }
    if (direction == 1) // 右
    {
        for (i = n; i > 0; i--)
        {
            if ((p[0] + 1) == p[i]) // 右边是自己的身体
            {
                printf("fail!\n");
                direction = -1;
            }
        }
    }
    if (direction == 2) // 上
    {
        for (i = n; i > 0; i--)
        {
            if ((p[0] - X) == p[i]) // 上边是自己的身体
            {
                printf("fail!\n");
                direction = -1;
            }
        }
    }
    if (direction == 3) // 左
    {
        for (i = n; i > 0; i--)
        {
            if ((p[0] - 1) == p[i]) // 左边是自己的身体
            {
                printf("fail!\n");
                direction = -1;
            }
        }
    }
    if (direction == 4) // 下
    {
        for (i = n; i > 0; i--)
        {
            if ((p[0] + X) == p[i]) // 下边是自己的身体
            {
                printf("fail!\n");
                direction = -1;
            }
        }
    }
}

void *key(void *arg) // 控制方向：w,s,a,d-->上下左右
{
    char k;
    while (1)
    {
        k = getchar();
        switch (k)
        {
        case 'w': // 上
        {
            direction = 2;
            break;
        }
        case 's': // 下
        {
            direction = 4;
            break;
        }
        case 'a': // 左
        {
            direction = 3;
            break;
        }
        case 'd': // 右
        {
            direction = 1;
            break;
        }
        case 'j': // 加速
        {
            delay = delay * 4 / 5;
            break;
        }
        case 'k': // 减速
        {
            delay = delay * 5 / 4;
            break;
        }
        case 27: // ESC
        {
            printf("退出！\n");
            direction = -1;
            break;
        }
        }

        usleep(100);
    }
}

int main()
{
    system("stty -icanon"); // 关闭缓冲区，输入字符无需回车直接接受
    pthread_t pid;
    pthread_create(&pid, NULL, key, NULL); // 创建线程，键盘控制
    randomApple();
    while (1)
    {
        show(); // 显示
        usleep(delay);
        isFail();          // 判断是否会咬到自己
        canEat();          // 判断是否能吃到*
        switch (direction) // 选择路径
        {
        case 1: // 右
        {
            moveRight();
            break;
        }
        case 2: // 上
        {
            moveUp();
            break;
        }
        case 3: // 左
        {
            moveLeft();
            break;
        }
        case 4: // 下
        {
            moveDown();
            break;
        }
        case -1: // 退出
        {
            pthread_cancel(pid); // 关闭线程
            return -1;
            break;
        }
        }
    }

    return 0;
}