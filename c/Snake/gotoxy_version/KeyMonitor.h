#ifndef _KEYMONITOR_H
#define _KEYMONITOR_H
#include "GlobalVar.h"
#include <stdio.h>
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <handleapi.h>
#include <processthreadsapi.h>
#include <windows.h>

#define KeyMonitor_Starter()                                                   \
    HANDLE hThread1 = CreateThread(NULL, 0, KeyMonitor, NULL, 0, NULL)
#define KeyMonitor_Stoper() CloseHandle(hThread1);
#elif defined(__linux__) || defined(__gnu_linux__)
#include <pthread.h>
#include <unistd.h>
#define KeyMonitor_Starter()                                                   \
    system("stty -icanon");                                                    \
    pthread_attr_t attr;                                                       \
    pthread_t tid;                                                             \
    pthread_attr_init(&attr);                                                  \
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);               \
    pthread_create(&tid, &attr, KeyMonitor, NULL);
#define KeyMonitor_Stoper() pthread_join(tid, NULL);
#elif defined(__APPLE__)
#endif

// KeyMonitor Function(Different Platform return value type is different)
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
DWORD WINAPI
#elif defined(__linux__) || defined(__gnu_linux__)
void *
#elif defined(__APPLE__)
#endif
KeyMonitor(void *arg) // Direction Control：w,s,a,d-->Up Down Left Right
{
    char k;
    while (1)
    {
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        k = _getch();
#elif defined(__linux__) || defined(__gnu_linux__)
        k = getchar();
#elif defined(__APPLE__)
#endif
        switch (k)
        {
        case 'w': // Up
        {
            if (direction != 4)
                direction = 2;
            break;
        }
        case 's': // Down
        {
            if (direction != 2)
                direction = 4;
            break;
        }
        case 'a': // Left
        {
            if (direction != 1)
                direction = 3;
            break;
        }
        case 'd': // Right
        {
            if (direction != 3)
                direction = 1;
            break;
        }
        case 'j': // SpeedUp
        {
            delay = delay * 4 / 5;
            break;
        }
        case 'k': // SpeedDown
        {
            delay = delay * 5 / 4;
            break;
        }
        case 27: // ESC
        {
            printf("Exit!\n");
            isPause = 0;
            direction = -1;
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
            return 0;
#elif defined(__linux__) || defined(__gnu_linux__)
            return NULL;
#elif defined(__APPLE__)
#endif
            break;
        }
        case ' ': // Space
        {
            if (isPause)
            {
                printf("Continue!\n");
            }
            else
            {
                printf("Pause!\n");
            }
            isPause = !isPause;
            break;
        }
        }
    }
}

#endif