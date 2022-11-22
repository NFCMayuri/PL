#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Only ASCII supported; bugs still exist on UTF-8
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
char *ToUpper(const char *str)
{
    char *ret = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    int i;
    if (ret == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                ret[i] = str[i] - 'a' + 'A';
            }
            else
            {
                ret[i] = str[i];
            }
        }
        ret[i] = '\0';
        return ret;
    }
}

void testToUpper()
{
    char array[] = "你好Go！\nHello,GO!";
    char *tmp = ToUpper(array);
    printf("ToUpper(%s)\n%s", array, tmp);
    free(tmp);
}
char *ToLower(const char *str)
{
    char *ret = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    int i;
    if (ret == NULL)
    {
        return NULL;
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                ret[i] = str[i] - 'A' + 'a';
            }
            else
            {
                ret[i] = str[i];
            }
        }
        ret[i] = '\0';
        return ret;
    }
}
void testToLower()
{
    char array[] = "你好Go！\nHello,GO!";
    char *tmp = ToLower(array);
    printf("ToLower(%s)\n%s", array, tmp);
    free(tmp);
}
int Count(const char *s, const char *sep)
{
    if (sep[0] == '\0')
    {
        return strlen(s) + 1;
    }
    int count = 0;
    while ((s = (strstr(s, sep))) != NULL)
    {
        s++;
        count++;
    }
    return count;
}
void testCount()
{
    char *s1 = "1145141919810";
    char *s2 = "2";
    char *s3 = "";
    printf("Count(\"%s\",\"%s\")=%d\n", s1, s2, Count(s1, s2));
    printf("Count(\"%s\",\"%s\")=%d\n", s1, s3, Count(s1, s3));
}
int main()
{
    // testEqualFold();
    // testIndexByte();
    // testIndex();
    // testToUpper();
    // testToLower();
    testCount();
}