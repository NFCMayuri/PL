#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PRINT(format, ...) printf(format, ##__VA_ARGS__);
inline void HELLO()
{
    PRINT("HELLO WORLD%s", " c");
}
void HELLO();
int main()
{
    HELLO();
    return 0;
}
