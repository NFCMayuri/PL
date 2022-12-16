#ifndef _SLEEP_H
#define _SLEEP_H
#include "GlobalVar.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#define SLEEPS(delay) Sleep(delay)
#elif defined(__linux__) || defined(__gnu_linux__)
#define SLEEPS(delay) usleep((delay)*1000)
#elif defined(__APPLE__)
#endif
#endif /* _SLEEP_H */
