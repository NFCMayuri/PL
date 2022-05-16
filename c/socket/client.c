#include <stdio.h>
#include <string.h>
#include <WinSock2.h>
// #pragma comment(lib, "ws2_32.lib")  //load ws2_32.dll

#define FORMAT_MSG "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: curl/7.79.1\r\nAccept: */*\r\n\r\n"

typedef void Fun(char *);

#define MAXLINE 100
#define MAXRECV 0xfff

// get admin from url(String Slicing)
void get_admin(const char *url, char *admin)
{
	int start = 7;
	if (strstr(url, "https"))
		start++;
	// String Slicing
	char *ret = strchr(url + start, '/');
	// String Slicing
	int admin_len = ret ? ret - url - start : strlen(url) - start;
	// String Slicing
	strncpy(admin, url + start, admin_len);
}

void get_admin_ip(const char *url, char *ip)
{
	char admin[30];
	get_admin(url, admin);

	struct hostent *phst = gethostbyname(admin);
	struct in_addr *iddr = (struct in_addr *)phst->h_addr;
	inet_ntoa(*iddr);

	// Convert the network address to the string format across the "."
	strcpy(ip, inet_ntoa(*iddr));
}

// if url contians https, return 443, else return 80
int get_url_port(const char *url)
{
	char *ret = strstr(url, "https");

	return ret ? 443 : 80;
}

void request(const char *sUrl, Fun fun)
{
	struct sockaddr_in servaddr;
	char buf[MAXRECV + 1];
	// char format_msg[] = (
	//	"GET %s HTTP/1.1\r\n"
	//	"Host: %s\r\n"
	//	"User-Agent: curl/7.79.1\r\n"
	//	"Accept: */*\r\n\r\n"
	//);
	char send_msg[strlen(FORMAT_MSG) + strlen(sUrl) * 2];
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
	sprintf(send_msg, FORMAT_MSG, sUrl, admin);
	// puts(send_msg);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(ip);
	servaddr.sin_port = htons(port);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	send(sockfd, send_msg, strlen(send_msg), 0);

	//分段接收处理
	do
	{
		r = recv(sockfd, buf, MAXRECV, 0);
		if (r < 255)
			buf[r] = '\0';
		fun(buf);
	} while (r == 255);

	closesocket(sockfd);
	WSACleanup();

	return;
}

// Example callback function
void print_msg(char *str)
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