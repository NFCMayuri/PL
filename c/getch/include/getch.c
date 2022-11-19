// test
#include "getch.h"
#include <stdio.h>

int main() {
  char ch;
  do {
    ch = sh_getch();

  } while (ch != ' ');
  printf("ch:'%c'", ch);
}