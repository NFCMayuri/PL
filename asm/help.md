nasm -f elf exec.asm -o exec.o
gcc -m32 exec.o -o exec
./exec ; echo $?


gcc -S exec.c
