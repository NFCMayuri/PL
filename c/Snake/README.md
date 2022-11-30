# Snake (CrossPlatform)

## How to build

### Linux

>gcc snake.c -lpthread

### windows

1. `snake_windows.c` file is the code using windowsapis and can be built directly

2. `snake.c` please use [POSIX Threads for Windows](https://sourceforge.net/projects/pthreads4w/)

> please use **MSVS or GNU GCC (e.g. MinGW or MinGW64(without win32pthreads)) supported** for pthreads4w support<br>
>gcc snake.c -I`${The Dir of pthreads4w}`<br>
>replace `${The Dir of pthreads4w}` according to your own setting

3. `snake_windows_opt.c` is the version avoiding refresh all output frequently, which lead to splash screen

#### The code under `clear_versiom` `gotoxy_version` has lots of bugs
