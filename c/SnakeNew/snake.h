#ifndef _SNAKE_H
#define _SNAKE_H
#include "clear.h"
#include "global_var.h"
#include "key_monitor.h"
#include "move.h"
#include "show_map.h"
#include "sleep.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Print String At (x,y) and make Cursor go to another place */

/* Random Food */
void RandomApple() {
  srand(time(NULL));
  do {
    i = rand() % HEIGHT;
    j = rand() %
        WIDTH; /* if random location is 0 ->*;else find again and again*/
  } while (map[i][j] != 0);
  map[i][j] = '*';
  // printf("Food is at (%02d,%02d)\n", i, j);
}

// exec when(before) moving
int canEat() {
  switch (direction) {
  // Right
  case 1: {
    if (*(snake[0] + 1) == '*') {
      return 1;
    }
    break;
  }
  // Up
  case 2: {
    if (*(snake[0] - WIDTH) == '*') {
      return 1;
    }
    break;
  }
  // Left
  case -1: {
    if (*(snake[0] - 1) == '*') {
      return 1;
    }
    break;
  }
  // Down
  case -2: {
    if (*(snake[0] + WIDTH) == '*') {
      return 1;
    }
    break;
  }
  }
  return 0;
}

// exec when(before) moving
int isFail() {
  if (snake[0] - WIDTH < &map[0][0] && direction == 2 ||
      snake[0] + WIDTH > &map[HEIGHT - 1][WIDTH - 1] && direction == -2 ||
      direction == 1 && (snake[0] - map[0]) % WIDTH == WIDTH - 1 ||
      direction == -1 &&
          (snake[0] - map[0]) % WIDTH == 0) // snake is not in the matrix
  {
    direction = 0;
    return 1;
  } else {
    switch (direction) {
    // Right
    case 1: {
      {
        for (i = length; i > 0; i--) {
          if ((snake[0] + 1) == snake[i]) // Right of the head is body
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
        for (i = length; i > 0; i--) {
          if ((snake[0] - WIDTH) == snake[i]) // Up of the head is body
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
        for (i = length; i > 0; i--) {
          if ((snake[0] - 1) == snake[i]) // Left of the head is body
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
        for (i = length; i > 0; i--) {
          if ((snake[0] + WIDTH) == snake[i]) // Down of the head is body
          {
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
void CheckInput() {
  if (direction == 0)
    return;
  if (direction != -directiontemp)
    direction = directiontemp;
}

void RandomApple();
void CheckInput();

#endif /* _SNAKE_H */
