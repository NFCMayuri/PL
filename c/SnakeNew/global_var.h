#ifndef _GLOBAL_VAR_H
#define _GLOBAL_VAR_H

#include <stdbool.h>
#define WIDTH 40
#define HEIGHT 20

#define HEAD '@' // The shape of snake head
#define HEAD_STRING "@"
#define BODY 'O' // The shape of snake body
#define BODY_STRING "O"
#define MAP_UNIT_STRING "[ ]"
#define FOOD_STRING "[*]"
char map[HEIGHT][WIDTH] = {{BODY, BODY, BODY, HEAD}}; // The initial char is 0
char *snake[HEIGHT * WIDTH] = {&map[0][3], &map[0][2], &map[0][1],
                               &map[0][0]}; // p[0] stand for snake head

int length = 3; // The length of snake body (without head)
int i, j;
signed char direction = 1;     // 1.Right;2.Up;-1.Left;-2.Down;0.Exit
signed char directiontemp = 1; // 1.Right;2.Up;-1.Left;-2.Down;0.Exit
int delay = 200;               // delay 0.2s(200ms)
bool isPause = 0;

#endif /* _GLOBAL_VAR_H */
