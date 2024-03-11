#ifndef _GOTOXY_H
#define _GOTOXY_H

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#define gotoxy(y, x)                                                           \
  {                                                                            \
    COORD coord = {(x), (y)}; /* coord */                                      \
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),                  \
                             coord); /* Move Cursor to coord */                \
  }
#elif defined(__linux__) || defined(__gnu_linux__)
#define gotoxy(y, x) printf("%c[%d;%df", 0x1B, ((y) + 1), ((x) + 1))
#elif defined(__APPLE__)
#endif

#endif /* _GOTOXY_H */
