#include "../include/str.h"
void strval(char **str1, const char *str2, int type)
{
    switch (type)
    {
    case 1:
    {
        *str1 = (char *)malloc(strlen(str2 + 1));
        sprintf(*str1, "%s", str2);
        printf("case 1 :%s\n", *str1);
        break;
    }
    case 2:
    {
        *str1 = (char *)realloc(*str1, strlen(*str1) + strlen(str2) + 1);
        sprintf(*str1, "%s%s", *str1, str2);
        printf("case 2 :%s\n", *str1);
    }
    break;
    case 3:
    {
        free(*str1);
        *str1 = (char *)malloc(strlen(str2 + 1));
        sprintf(*str1, "%s", str2);
        printf("case 3 :%s\n", *str1);
        break;
    }
    }
}