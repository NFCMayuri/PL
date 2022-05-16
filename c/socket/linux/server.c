#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 3339
int main()
{
    char *sendbuf = "thanks";
    char buf[256];
    int s_fd, c_fd;
    int s_len, c_len;
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = PORT;
    s_len = sizeof(s_addr);
    bind(s_fd, (struct sockaddr *)&s_addr, s_len);
    listen(s_fd, 10);
    while (1)
    {
        printf("please wait a moment\n");
        c_len = sizeof(c_addr);
        c_fd = accept(s_fd, (struct sockaddr *)&c_addr, &c_len);
        recv(c_fd, buf, sizeof(buf), 0);
        printf("receive message: %s\n", buf);
        send(c_fd, sendbuf, sizeof(sendbuf), 0);
        close(c_fd);
    }
    return 0;
}