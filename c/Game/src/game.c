#include "../include/koishi.h"
LEVEL getlevel()
{
    LEVEL l;
    printf("please input the level number:\n\
    1.easy\n\
    2.normal\n\
    3.hard\n\
    4.extreme\n");
    scanf("%d", &l);
    rewind(stdin);
    return l;
}