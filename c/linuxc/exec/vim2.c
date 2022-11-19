#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
extern char **environ;
int main(int argc, char *argv[])
{
    printf("This message will show");
    sleep(10);
    execlp("/bin/vi", argv[1], (char *)NULL);
    printf("This message will not show");
}
