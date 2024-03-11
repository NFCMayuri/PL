#ifndef _SHWOMAP_H
#define _SHWOMAP_H

#include "clear.h"
#include "global_var.h"
#include <stdio.h>
inline void PaintMap() {
  clear_screen();
  printf("\nYour Score is:%d\n", length - 3);
  for (i = 0; i < (WIDTH)*2; i++)
    printf("_");
  printf("\n");
  for (i = 0; i < (HEIGHT); i++) {
    for (j = 0; j < (WIDTH); j++) {
      if (map[i][j] == 0)
        printf("_|");
      else
        printf("%c|", map[i][j]);
    }
    printf("\n");
  }
  printf("\n"
         "w,s,a,d->Up Down Left Right;\n"
         "j,k->Speed Up/Down;\n"
         "ESC: Exit\n");
}
void PaintMap();

#endif /* _SHWOMAP_H */
