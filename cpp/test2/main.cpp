#include <stdio.h>
auto caller()
{
    int *cnt = new int;
    *cnt = 0;
    return [&]
    {
        (*cnt)++;
        printf("%d\n", *cnt);
        if (*cnt == 4)
        {
            delete cnt;
        }
    };
}
int main()
{
    auto next = caller();
    next();
    next();
    next();
    next();
    next();
    return 0;
}
