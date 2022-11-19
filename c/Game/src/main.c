#include "../include/game.h"
extern LEVEL getlevel();
int main()
{
    char *level[4] = {"easy", "normal", "hard", "extreme"};
    LEVEL l;
    l = getlevel();
    while (l < 1 || l > 4)
    {
        printf("the number you input(%d) is not listed\nplease input again:\n", l);
        l = getlevel();
    }
    printf("you choose %d %s\n", l, level[l - 1]);
    return 0;
}