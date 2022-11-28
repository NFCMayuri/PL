#include <conio.h>
#include <stdio.h>
#include <windows.h>


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define gotoxy(y, x)                                                           \
    {                                                                          \
        COORD coord = {(x), (y)}; /* coord */                              \
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),              \
                                 coord); /* Move Cursor to coord */            \
    }
int main()
{
    /* 我的第一个 C 程序 */
    system("clear");
    printf("Hello, World! \n0123456789\n1234567890\n2345678901\n3456789012\n4567890123\n5678901234");
    gotoxy(3, 2);
    printf("asdfdsasdf");
    gotoxy(8, 9);
    printf("00");
    return 0;
}
