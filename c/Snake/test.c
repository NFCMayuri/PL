#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PRINT(s) printf("%s", #s);
inline void HELLO()
{
    PRINT(HELLO)
}
void HELLO();
int main()
{
    HELLO();
    return 0;
}
