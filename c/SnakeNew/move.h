#ifndef _MOVE_H
#define _MOVE_H

#include "global_var.h"
inline void moveBody() {
  *snake[length] = 0;
  for (i = length; i > 0; i--) {
    snake[i] =
        snake[i - 1]; /* per part goes to the address of the next part of body*/
  }
  *snake[0] = BODY; /* The First part of snake body come to snake head*/
}

inline void moveRight() {
  moveBody();
  snake[0] = snake[0] + 1; /* Move snake head */
  *snake[0] =
      HEAD; /* change the char of new head(new address)'s shape to HEAD */
}
inline void moveLeft() {
  moveBody();
  snake[0] = snake[0] - 1;
  *snake[0] = HEAD;
}
inline void moveDown() {
  moveBody();
  snake[0] = snake[0] + WIDTH;
  *snake[0] = HEAD;
}
inline void moveUp() {
  moveBody();
  snake[0] = snake[0] - WIDTH;
  *snake[0] = HEAD;
}
void moveBody();
void moveRight();
void moveLeft();
void moveDown();
void moveUp();

#endif /* _MOVE_H */
