// test
#include "getch.h"
#include "keyboard.h"
#include <stdio.h>
int sh_getch(void);
int main() {
  char ch;
  do {
    ch = sh_getch();
    printf("You press \'%c\'         \nAscii: %d\n\n", ch, ch);
  } while (ch != ESC);
  printf("You press \'%c\'         \nAscii: %d\n\n", ch, ch);
  printf("ch:\'%c'         \nExiting......", ch);
}