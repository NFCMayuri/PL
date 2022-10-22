#include <cstdio>
#include <cstring>
int min(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}
int add(const char *a, const char *b)
{
    char c[100];
    sprintf(c, "%s%s", a, b);
    return (int)(*c);
}
int add(int a, int b)
{
    return a + b;
}

int calc(int (*fp)(int a, int b), int a, int b)
{
    return (*fp)(a, b);
}

int main(int argc, char *argv[])
{
    int a = 1, b = 2;
    printf("%d %d=%d\n", a, b, calc(add, a, b));
}
