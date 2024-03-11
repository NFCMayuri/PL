#ifndef _KEYMONITOR_H
#define _KEYMONITOR_H

#include "canonical_mode.h"
#include "global_var.h"
#include <stdio.h>
#include <threads.h>

int KeyMonitor(void *arg) // Direction Control：w,s,a,d-->Up Down Left Right
{

  char k;
  while (1) {
    if (direction == 0) {
      thrd_exit(0);
    }
    k = getchar();
    switch (k) {
    case 'w': // Up
    {
      directiontemp = 2;
      break;
    }
    case 's': // Down
    {
      directiontemp = -2;
      break;
    }
    case 'a': // Left
    {
      directiontemp = -1;
      break;
    }
    case 'd': // Right
    {
      directiontemp = 1;
      break;
    }
    case 'j': // SpeedUp
    {
      delay = delay * 4 / 5;
      if (delay == 0)
        delay = 1;
      break;
    }
    case 'k': // SpeedDown
    {
      delay = delay * 5 / 4;
      break;
    }
    case 27: // ESC
    {
      printf("\nExit!\n");
      direction = 0;
      directiontemp = 0;
      thrd_exit(0);
      // exit(0);
      break;
    }
    case ' ': // Space
    {
      if (isPause) {
        printf("\nContinue!\n");
      } else {
        printf("\nPause!\n");
      }
      isPause = !isPause;
      break;
    }
    }
  }
}

#endif /* _KEYMONITOR_H */
