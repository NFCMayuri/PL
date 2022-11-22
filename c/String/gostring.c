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

// Only ASCII supported; bugs still exist on UTF-8
#define HasPrefix(s, prefix) ((_Bool)(strstr((s), (prefix)) == (s)))
void testHasPrefix()
{
    printf("%s\n", HasPrefix("abcdefg", "abc") ? "True" : "False");
    printf("%s\n", HasPrefix("abcdefg", "ac") ? "True" : "False");
    printf("%s\n", HasPrefix("你好", "\xE4") ? "True" : "False");
}

// Only ASCII supported; bugs still exist on UTF-8
#define HasSuffix(s, prefix)                                                   \
    ((_Bool)(strcmp((s) + strlen((s)) - strlen((prefix)), (prefix)) == 0))
void testHasSuffix()
{
    printf("%s\n", HasSuffix("abcdefg", "efg") ? "True" : "False");
    printf("%s\n", HasSuffix("abcdefg", "eg") ? "True" : "False");
    printf("%s\n", HasSuffix("你好", "\xBD") ? "True" : "False");
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

#define Contains(str, substr) ((_Bool)strstr((str), (substr)))
void testContains()
{
    char s1[] = "I love Java Programming!";
    char s2[] = "Programming";
    char s3[] = "网络上学习Java";
    char s4[] = "I love Java Programming!";
    char s5[] = "I love Java programming!";
    char s6[] = "Java";
    char s7[] = "Java programming!";
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s2, Contains(s1, s2));
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s3, Contains(s1, s3));
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s4, Contains(s1, s4));
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s5, Contains(s1, s5));
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s6, Contains(s1, s6));
    printf("Contains(\"%s\",\"%s\")=%d\n", s1, s7, Contains(s1, s7));
    printf("Contains(\"%s\",\"%s\")=%d\n", "", "", Contains("", ""));
    printf("Contains(\"%s\",\"%s\")=%d\n", "1", "", Contains("1", ""));
}

int main()
{
    // testEqualFold();
    // testIndexByte();
    // testIndex();
    testHasPrefix();
    testHasSuffix();
    // testToUpper();
    // testToLower();
    // testCount();
    // testContains();
}