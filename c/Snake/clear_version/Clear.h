#ifndef _CLEAR_H
#define _CLEAR_H

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#define Clear() printf("\033c");
#elif defined(__linux__) || defined(__gnu_linux__)
#define Clear() printf("\033c");
#elif defined(__APPLE__)
#endif

#endif /* _CLEAR_H */
