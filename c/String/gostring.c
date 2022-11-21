#include <stdio.h>
#include <string.h>
// Only English supported; utf8 still have bugs
_Bool EqualFold(const char *s1, const char *s2)
{
    int i = strlen(s1);
    if (i != strlen(s2))
    {
        return 0;
    }
    else
    {
        while (i + 1)
        {
            if (s1[i] != s2[i])
            {
                if ((s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'a' &&
                     s2[i] <= 'z' && s1[i] - s2[i] == 'A' - 'a'))
                {
                    i--;
                }
                else if ((s2[i] >= 'A' && s2[i] <= 'Z' && s1[i] >= 'a' &&
                          s1[i] <= 'z' && s2[i] - s1[i] == 'A' - 'a'))
                {
                    i--;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                i--;
            }
        }
    }
    return 1;
}
void testEqualFold()
{
    printf("%s", EqualFold("AbcDefGhIjKl", "aBcdEfGhiJkl") ? "True" : "False");
}

int IndexByte(const char *s, char c)
{
    int i = 0;
    while (s[i] != c)
    {
        if (s[i] == '\0')
        {
            return -1;
        }
        else
        {
            i++;
        }
    }
    return i;
}
void testIndexByte()
{
    printf("%d\n", IndexByte("chicken", 'k'));
    printf("%d\n", IndexByte("chicken", 'd'));
    printf("%d\n", IndexByte("你好", '\xA0'));
}
int Index(const char *s, const char *sep)
{
    char *i = strstr(s, sep);
    if (i == NULL)
    {
        return -1;
    }
    else
    {
        return i - s;
    }
}
void testIndex()
{
    printf("%d\n", Index("RUNOOB", "NOOB"));
    printf("%d\n", Index("你好", "\xA0"));
}
_Bool HasPrefix(const char *s, const char *prefix)
{
    if (strstr(s, prefix) - s != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    // testEqualFold();
    // testIndexByte();
    testIndex();
}