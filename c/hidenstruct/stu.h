#ifndef _STU_H
#define _STU_H
struct stu;
extern struct stu *new_stu();
extern void set_id(struct stu *s, const char *id);
extern char *get_id(struct stu *);
#endif // !_STU_H