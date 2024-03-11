#include "Snake.h"
int main() {
  KeyMonitor_Starter();
  ShowMap();
  RandomApple();
  while (1) {
    ShowMap();
    do {
      SLEEPS(delay);
    } while (isPause);
    CheckInput();
    switch (isFail()) {
    case 0:
      break;
    case 1:
      printf("Fail!Don't hit the wall!\nYour Final Score is:%d\n", n - 3);
      return -1;
      break;
    case 2:
      printf("Fail!Don't eat your body!\nYour Final Score is:%d\n", n - 3);
      return -1;
      break;
    }

    if (canEat()) {
      n++; // length++
      p[n] = p[n - 1];
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
  KeyMonitor_Stoper();
}
