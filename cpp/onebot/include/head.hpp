#ifndef _head_hpp
#define _head_hpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
// extern "C"
//{
#include "../include/str.h"
//}
struct body_link
{
    int type;
    void *data;
    struct body_link *next;
};
struct head_link
{
    int type[2];
    char *name;
    struct body_link *head;
    struct body_link **location;
    struct test *next;
};
struct head_link *add()
{
    struct head_link *temp = (struct head_link *)malloc(sizeof(struct head_link));
    return temp;
}
#endif
