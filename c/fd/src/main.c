#include "../include/fd.h"
int main()
{
    char *path = "file.txt";
    int fd;
    char buf[40], buf2[] = "hello world";
    int n, i;
    if ((fd = open(path, O_RDWR)) < 0)
    {
        perror("open file failed");
        return 1;
    }
    else
    {
        printf("open file successfully\n");
    }

    if ((n = read(fd, buf, 20)) < 0)
    {
        perror("read failed");
        return 1;
    }
    else
    {
        printf("output read data:\n");
        printf("%s\n", buf);
    }
    if ((i = lseek(fd, 11, SEEK_SET)) < 0)
    {
        perror("lseek error");
        return 1;
    }
    else
    {
        if (write(fd, buf2, 11) < 0)
        {
            perror("write error");
            return 1;
        }
        else
        {
            printf("write successfully\n");
        }
    }
    close(fd);

    if ((fd = open(path, O_RDWR)) < 0)
    {
        perror("open file failed");
        return 1;
    }
    else
    {
        if ((n = read(fd, buf, 40) < 0))
        {
            perror("open file 2  failed");
            return 1;
        }
        else
        {
            printf("read the changed data:\n");
            printf("%s\n", buf);
        }
        if (close(fd) < 0)
        {
            perror("close file failed");
            return 1;
        }
        else
        {
            printf("goodbye\n");
        }
    }
    return 0;
}
