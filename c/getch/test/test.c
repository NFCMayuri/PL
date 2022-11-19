// test
#include "getch.h"
#include "keyboard.h"
#include <stdio.h>
int sh_getch(void);
int main() {
  char ch;
  do {
    ch = sh_getch();
    switch (ch) {
    case 'w':
      printf("You press w\n");
      break;
    case 'a':
      printf("You press a\n");
      break;
    case 's':
      printf("You press s\n");
      break;
    case 'd':
      printf("You press d\n");
      break;
    }
  } while (ch != ESC);
  printf("ch:\'%c'\nExiting......", ch);
}