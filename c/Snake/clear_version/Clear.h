#ifndef _CLEAR_H
#define _CLEAR_H

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#define Clear() system("cls")
#elif defined(__linux__) || defined(__gnu_linux__)
#define Clear() system("clear")
#elif defined(__APPLE__)
#endif

#endif