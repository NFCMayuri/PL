#include <stdio.h>
#include <string.h>
#include <WinSock2.h>
// #pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

typedef void Fun(char *);

#define MAXLINE 100

void get_admin(const char * url, char *admin)
{
    int start = 7;
    if (strstr(url, "https"))
        start++;
    char *ret = strchr(url+start, '/');
	int admin_len = ret ? ret-url-start : strlen(url)-start;

    strncpy(admin, url+start, admin_len);
}

void get_admin_ip(const char * url, char *ip)
{
    char admin[30];
	get_admin(url, admin);

    struct hostent *phst = gethostbyname(admin);
    struct in_addr * iddr = (struct in_addr*)phst->h_addr;
    inet_ntoa(*iddr);
    strcpy(ip, inet_ntoa(*iddr));
}

int get_url_port(const char * url)
{
    char *ret = strstr(url, "https");
    
    return ret ? 443 : 80;
}

void request(const char * sUrl, Fun fun)
{
	struct sockaddr_in servaddr;
	char buf[MAXBYTE];
	char format_msg[] = (
		"GET %s HTTP/1.1\r\n"
		"Host: %s\r\n"
		"User-Agent: curl/7.79.1\r\n"
		"Accept: */*\r\n\r\n"
	);
	char send_msg[strlen(format_msg) + strlen(sUrl)*2];
	char admin[30];
    char ip[20];
    int port;
	int r;
	SOCKET sockfd;

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

	port = get_url_port(sUrl);
	get_admin_ip(sUrl, ip);
    get_admin(sUrl, admin);
	sprintf(send_msg, format_msg, sUrl, admin);
	// puts(send_msg);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
	servaddr.sin_port = htons(port);
    
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	send(sockfd, send_msg, strlen(send_msg), 0);

	do {
		r = recv(sockfd, buf, MAXBYTE, 0);
		if (r < 255)
			buf[r] = '\0';
		fun(buf);
	} while(r == 255);

	closesocket(sockfd);
    WSACleanup();

	return;
}

void print_msg(char * str)
{
	printf("%s", str);
}

int main(int argc, char *argv[])
{
	char str[MAXLINE] = {0};

	if (argc < 2)
	{
		printf("usage: ./client message\n");
		exit(0);
	}

	system("chcp 65001");
	request(argv[1], print_msg);

	// FILE *fp = fopen("test.txt", "w");
	// fputs(str, fp);
	// fclose(fp);

	return 0;
}