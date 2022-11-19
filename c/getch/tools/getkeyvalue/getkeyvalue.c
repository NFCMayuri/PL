#include "getch.h"
#include <stdio.h>
int sh_getch(void);
int main() {
  char ch;
  while ((ch = sh_getch()) != 0x1B) /* ESC to quit */
  {
    printf("%d \n", ch);
  }
}