# Snake (CrossPlatform)

## How to build

Linux
>gcc snake.c -lpthread

if you want to build it on windows

1. please use [POSIX Threads for Windows](https://sourceforge.net/projects/pthreads4w/)

> please use **MSVS or GNU GCC (e.g. MinGW or MinGW64(without win32pthreads)) supported** for pthreads4w support

>gcc snake.c -I${The Dir of pthreads4w}

>relpace ${The Dir of pthreads4w} according to your own setting

2. `snake_windows.c` file is the code using windowsapis
