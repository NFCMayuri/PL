#include "../include/bomb.h"
int bomb(int times,char Char){
    printf("%c[47;31m",0x1B);
    while (times>0){
        putchar(Char);
        times--;
    }
    printf("%c[0m\n",0x1B);
    return 0;
}
