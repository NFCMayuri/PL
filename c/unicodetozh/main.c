#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(void)
{
char str[12];
wchar_t wstr[] = { 0x52B3, 0x788C, 0 };
setlocale(LC_ALL, "");
wcstombs(str, wstr, sizeof(str)/sizeof(char));
printf("%s", str);
return 0;
}
