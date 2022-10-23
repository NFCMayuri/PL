#include "../include/bomb.h"
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
