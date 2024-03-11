#ifndef _CLEAR_H
#define _CLEAR_H

#if defined(__linux__) || defined(__gnu_linux__)
#define clear_screen() printf("\033c");
#elif defined(__APPLE__)
#define clear_screen() printf("\033c");
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#define clear_screen() printf("\033c");
#endif

#endif /* _CLEAR_H */
