#include <stdio.h>
int main()
{
    union test
    {
        unsigned int a : 1;
        unsigned int b : 2;
        unsigned int c : 1;
    };
    union test test2;
    test2.a = 1;
    printf("%d\n", test2.a);
}
