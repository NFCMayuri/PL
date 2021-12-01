#include <stdio.h>
#include <stdbool.h>
int bomb(int times,char Char){
    printf("%c[47;31m",0x1B);
    while (times>0){
        putchar(Char);
        times--;
    }
    printf("%c[0m\n",0x1B);
}
int main(int argc,char *argv[]){
    char Char;
    if (1 == argc){
        Char='~'; 
        printf("plz input a char:");
        Char = getchar();
    }else 
    {
         Char = argv[1][0];
    }
    while (true) {
        bomb(8,Char);
        bomb(9,Char);
        bomb(10,Char);
        bomb(11,Char);
        bomb(10,Char);
        bomb(9,Char);
        bomb(8,Char);

    }
}
