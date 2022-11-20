// test
#include "getch.h"
#include "keyboard.h"
#include <stdio.h>
int sh_getch(void);
int main() {
  char ch;
  do {
    ch = sh_getch();
    if (ch > 31 && ch < 127) {
      printf("You press \'%c\'         \nAscii: 0x%x\n\n", ch, ch);

    } else {
      printf("Ascii: 0x%x", ch);
      printf("\n\n");
    }
  } while (ch != 'q');
  printf("ch:\'%c'\nExiting......", ch);
}