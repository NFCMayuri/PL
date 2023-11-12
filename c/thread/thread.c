#include <stdio.h>
#include <threads.h>
#include <time.h>
int thrd_proc(void *varg){
  int times = 5;
  struct timespec time_point={1,0};
  while (times--){
    printf("The %d times:%s\n",times+1,(char*)varg);
    thrd_sleep(&time_point, NULL);
  }
  return 0;
}
int main(int argc, char *argv[])
{
  thrd_t t1, t2;
  thrd_create(&t1, thrd_proc, "thread 1 running");
  thrd_create(&t2, thrd_proc, "thread 2 running");
  thrd_join(t2,NULL);
  thrd_join(t1,NULL);
  return 0;
}
