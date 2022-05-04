#ifndef _KOISHI_H_
#define _KOISHI_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum level {
    easy=1,
    normal,
    hard,
    extreme
    }LEVEL;
LEVEL getlevet(void);
#endif