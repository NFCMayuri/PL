#ifndef _GLOBALVAR_H
#define _GLOBALVAR_H

#include <stdbool.h>
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
int delay = 200; // delay 0.2s(200ms)
bool isPause = 0;
#endif