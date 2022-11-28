#ifndef _SNAKE_H
#define _SNAKE_H
#include "KeyMonitor.h"
#include "globalvar.h"
#include "gotoxy.h"
#include "mapInit.h"
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
#include <handleapi.h>
#include <processthreadsapi.h>
#elif defined(__linux__) || defined(__gnu_linux__)
#include <pthread.h>
#elif defined(__APPLE__)
#endif
#endif