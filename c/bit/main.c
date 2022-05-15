#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char *u2word(int u);
int main()
{
    int a = 0x52B3;
    printf("%s\n", u2word(a));
}
const char *u2word(int u)
{
    char *temp = (char *)malloc(sizeof(int));
    sprintf(temp, "%X", u);
    printf("\\u%s\n", temp);
    temp[0] = '\\';
    temp[1] = 'u';
    return temp;
}
