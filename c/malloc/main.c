#include <stdio.h>
#include <stdlib.h>
int main(){
        int *a=(int *)malloc(sizeof(int));
        *a=4;
        printf("a:%p\n",a);
    {
        free(a);
        int *b=(int *)malloc(sizeof(int));
        printf("a:%p\n",a);
        printf("b:%p\n",b);
    }
    printf("%d\n",*a);
}
