#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
struct stu {
  char id[20];
  int score;
};
struct stu *new_stu() {
  struct stu *s = malloc(sizeof(struct stu));
  return s;
};
void set_id(struct stu *s, const char *id) { strcpy(s->id, id); }
char *get_id(struct stu *s) { return s->id; }
