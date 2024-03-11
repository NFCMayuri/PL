#include "snake.h"
#include "canonical_mode.h"
#include "key_monitor.h"
#include <threads.h>
int main() {
  disable_canonical_mode();
  thrd_t thr;
  int thr_ret;
  thr_ret = thrd_create(&thr, KeyMonitor, NULL);
  if (thr_ret != thrd_success) {
    printf("error!!!\n");
    getchar();
    exit(-1);
  }
  PaintMap();
  RandomApple();
  while (1) {
    PaintMap();
    do {
      ms_sleep(delay);
    } while (isPause);
    CheckInput();
    switch (isFail()) {
    case 0:
      break;
    case 1:
      printf("Fail!Don't hit the wall!\nYour Final Score is:%d\n", length - 3);
      return -1;
      break;
    case 2:
      printf("Fail!Don't eat your body!\nYour Final Score is:%d\n", length - 3);
      return -1;
      break;
    }

    if (canEat()) {
      length++; // length++
      snake[length] = snake[length - 1];
      RandomApple();
    }

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
    case -1: // Left
    {
      moveLeft();
      break;
    }
    case -2: // Down
    {
      moveDown();
      break;
    }
    }
    if (direction == 0) {
      break;
    }
  }
}
