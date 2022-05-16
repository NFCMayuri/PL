#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 3339
int main()
{
    int sockfd;
    int len;
    struct sockaddr_in addr;
    int newsockfd;
    char *buf = "come on";
    int len2;
    char rebuf[40];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = PORT;
    len = sizeof(addr);
    newsockfd =connect(sockfd, (struct sockaddr *)&addr, len);
    if (newsockfd = -1)
    {
        perror("connect failed");
        return 1;
    }
    len2 = sizeof(rebuf);
    send(sockfd, buf, sizeof(buf), 0);
    sleep(10);
    recv(sockfd,rebuf,len2,0);
    rebuf[sizeof(rebuf)+1] = '\0';
    printf("receive message: %s\n", rebuf);
    close(sockfd);
    return 0;
}