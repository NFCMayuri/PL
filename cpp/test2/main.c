#include <stdio.h>
void (*add)();
void addf(){
    int *a = (int *)malloc(sizeof(int));
    *a =4;
}
int main(int argc, char *argv[])
{
    add()* fp=addf();
    fp();
    printf("%d\n",*a );
    return 0;
}
