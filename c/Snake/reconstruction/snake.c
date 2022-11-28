#include "snake.h"
#include "Sleep.h"
#include "globalvar.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    KeyMonitor_Starter();
    mapInit();
    RandomApple();
    while (1)
    {
        do
        {
            SLEEPS(delay);
        } while (isPause);
        switch (isFail())
        {
        case 0:
            break;
        case 1:
            PRINTXY(HEIGHT + 7, 0, "Fail!\nDon't hit the wall!\n");
            break;
        case 2:
            PRINTXY(HEIGHT + 7, 0, "Fail!\nDon't eat your body!\n");
            break;
        }
        canEat();
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
            printf("Your Final Score is:%d\n", n - 3);
            return -1;
            break;
        }
        }
    }
    KeyMonitor_Stoper();
}