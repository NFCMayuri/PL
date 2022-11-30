#ifndef _RANDOM_H
#define _RANDOM_H
#include <stdlib.h>
#define RANDOM_INT(MIN, MAX) (rand() % ((MAX) - (MIN)) + (MIN))
#endif