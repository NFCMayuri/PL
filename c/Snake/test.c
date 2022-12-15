#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define gotoxy(y, x) printf("%c[%d;%df", 0x1B, ((y) + 1), ((x) + 1))
int main()
{
    system("stty -icanon");
    system("clear");
    printf("Hello, World! "
           "\n0123456789\n1234567890\n2345678901\n3456789012\n4567890123\n56789"
           "01234");
    getchar();
    gotoxy(3, 2);
    printf("asdfdsasdf");
    gotoxy(8, 9);
    printf("00");
    printf("\033c");
    return 0;
}
