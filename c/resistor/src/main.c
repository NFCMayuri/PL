#include <stdio.h>
#include "../include/resistorcal.h"
int main(){
    printf("Welcome to Mayuri's Resistor Calculator(Only for separate routes and 2 resistor in it)\n");
    printf("Make your choice\n> 1.Your have the two resistors of separate routes\n> 2. Your have one of the resistors in the separate routes and the total resistor\nAny other choice is to exit\n");
    char choice;
    scanf("%c",&choice);
    switch (choice){
        case '1' : printf("Please input your args as [R1 R2]:\n");break;
        case '2' : printf("Please input your args as [R1 R]:\n");break;
        default : printf("exiting\n");return 0;break;
    }
    double r1 = -1 ,r2 = -1;
    scanf("%lf %lf",&r1,&r2);
    while ((r1<0)||(r2<0)) {
        printf("args don't meet the requirement(R>0)\n");
        printf("please input them again:\n");
        scanf("%lf %lf",&r1,&r2);

    }
    switch (choice){
        case '1' : printf("R=%lf",resistorcal(r1,r2,choice));break;
        case '2' : printf("R2=%lf",resistorcal(r1,r2,choice));break;
    }
}
