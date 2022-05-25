#include "../include/Fib.h"
int main(int argc, char argv[])
{
    unsigned int n, fib;
    scanf("%d", &n);
    rewind(stdin);
    fib = Fib(n);
    if (fib != -1)
    {
        printf("Fib(%d)=%d", n, fib);
    }
    else
    {
        printf("The input is not a valid value.");
    }
    return 0;
}