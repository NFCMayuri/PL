#include "stu.h"
#include <stdio.h>


int main() {
  struct stu *s;
  s = new_stu();
  set_id(s, "114514");
  printf("%s", get_id(s));
  return 0;
}