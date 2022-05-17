#include <time.h>
#include <stdio.h>
#include <string.h>
#include <WinSock2.h>
// #pragma comment(lib, "ws2_32.lib")  //load ws2_32.dll

typedef void Fun(char *, int);

#define MAXLINE 100
#define MAXRECV 0xfff
#define PROXY_IP "127.0.0.1"
#define PROXY_PORT 7890
#define PROXY_FLAG 1

FILE *fp = NULL;
_Bool dowm_flag = 0;

const char *format_headers = (
	"GET %s HTTP/1.1\r\n"
	"Host: %s\r\n"
	"Connection: keep-alive\r\n"
	"Accept: */*\r\n"
	"%s"
	"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.64 Safari/537.36 Edg/101.0.1210.47\r\n\r\n"
);

// Get admin from url(String Slicing)
void get_admin(const char * url, char *admin)
{
    int start = 7;
    if (strstr(url, "https"))
        start++;
	char *r1 = strchr(url+start, ':');
    char *r2 = strchr(url+start, '/');
	int admin_len = r1 ? r1-url-start : r2 ? r2-url-start : strlen(url)-start;

    strncpy(admin, url+start, admin_len);
}

void get_admin_ip(const char *url, char *ip)
{
    char admin[30] = {0};
	get_admin(url, admin);

    struct hostent *phst = gethostbyname(admin);
    struct in_addr * iddr = (struct in_addr*)phst->h_addr;
    inet_ntoa(*iddr);
    strcpy(ip, inet_ntoa(*iddr));
}

// If url contians https, return 443, else return 80
int get_url_port(const char * url)
{
	int port;
	char *p;

	if (p = strchr(url+7, ':'))
	{
		sscanf(p+1, "%d", &port);
		return port;
	}
    
    char *ret = strstr(url, "https");
    return ret ? 443 : 80;
}

_Bool get_file_name(char *header, char *filename)
{
	char str[200];
	char *p;
	p = strstr(header, "Content-Disposition");
	if (p == NULL) return 0;
	sscanf(p, "%*s %[^\n]", str);
	p = strchr(str, '\'');
	if (p == NULL) return 0;
	p += 2;
	strncpy(filename, p, strlen(p)-1);
	filename[strlen(p)-1] = '\0';
	
	return 1;
}

void check_type(const char *url, char *type, char *filename, int nameflag)
{
	char type_list[][15] = {"json", "text", "html", "x-javascript"};

	if (type == NULL)
		return;
	
	for (int i=0; i<4; i++) 
	{
		if (strstr(type, type_list[i]))
			return;
	}

	if (!nameflag)
	{
		char *p = strrchr(url, '/') + 1;
		char *q = strrchr(p, '?');
		if (q)
		{
			strncpy(filename, p, q-p);
			filename[q-p] = '\0';
		}
		else
		{
			strncpy(filename, p, strlen(p));
			filename[strlen(p)] = '\0';
		}
		if (strchr(p, '.') == NULL)
		{
			char ext[10] = {0};
			ext[0] = '.';

			sscanf(type, "%*[^/]/%[a-zA-Z]", ext+1);
			strcat(filename, ext);
		}
	}
	fp = fopen(filename, "wb");
	dowm_flag = 1;
}

int request(const char *sUrl, Fun *fun)
{
	struct sockaddr_in servaddr;
	clock_t start, end;
	SOCKET sockfd;
	
	char buf[MAXRECV+1] = {0};
	char send_msg[strlen(format_headers) + strlen(sUrl)*2];
	char data_type[10] = "text/plain";
	char header[2500] = {0};
	char admin[30] = {0};
	char filename[100];
    char ip[20] = {0};
	_Bool chunked = 1;
	int header_len = 0;
	int cont_len = 0;
	int data_len = 0;
	int status = 0;
	int r_len;
    int port;
	char *p;
	char *q;
	
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

	port = get_url_port(sUrl);
    get_admin(sUrl, admin);
	get_admin_ip(sUrl, ip);
	sprintf(send_msg, format_headers, sUrl, admin, \
		strstr(admin, "i.pximg.net")?"referer: http://www.pixiv.net/\r\n":""
	);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(PROXY_FLAG?PROXY_IP:ip);
	servaddr.sin_port = htons(PROXY_FLAG?PROXY_PORT:port);
    
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	send(sockfd, send_msg, strlen(send_msg), 0);

	start = clock();

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		r_len = recv(sockfd, buf, MAXBYTE, 0);
		memmove(header+header_len, buf, r_len);
		header_len += r_len;
		p = strstr(header, "\r\n\r\n");
		if (p)
		{
			p[0] = '\0';
			p += 4;
			data_len = header_len-(p-header);
			break;
		}
	}

	sscanf(header, "%*s %d", &status);
	if (q = strstr(header, "Content-Type"))
		sscanf(q, "%*s %s", data_type);
	check_type(sUrl, data_type, filename, get_file_name(header, filename));
	
	// print response
	if (status != 200)
		printf("\n%s\n\n", header);
	fun(p, data_len);

	if (strstr(header, "Transfer-Encoding: chunked") == NULL)
	{
		chunked = 0;
		p = strstr(header, "Content-Length");
		sscanf(p, "%*s %d", &cont_len);
	}

	while(1)
	{
		if (!chunked)
		{
			if (data_len >= cont_len) break;
		}
		else
		{
			if (strstr(buf, "\r\n0\r\n\r\n")) break;
		}
		r_len = recv(sockfd, buf, MAXRECV, 0);
		buf[r_len] = '\0';
		data_len += r_len;
		fun(buf, r_len);
		if (dowm_flag)
		{
			end = clock();
			printf("\r");
			printf("downloading %d/%d bytes %.0f%% - %.1fs",\
				data_len, cont_len, (data_len/(float)cont_len)*100, (end-start)/1000.0
			);
		}
	}

	fclose(fp);
	closesocket(sockfd);
    WSACleanup();

	return status;
}

// Example callback function
void process_data(char * str, int len)
{
	if (!dowm_flag)
	{
		printf("%s", str);
	}
	else
	{
		fwrite(str, sizeof(char), len, fp);
	}
}

// Simply replace https with http
void https_to_http(char **url)
{
	if (url[1][4] == 's')
	{
		memmove(url[1]+1, "http", 4);
		url[1]++;
	}
}

int main(int argc, char *argv[])
{
	clock_t start, end;
	// char *url = "http://tva1.sinaimg.cn/large/ec43126fgy1h1753rj0z3j20k00zk7b7.jpg";
	// char *url = "http://api.lolicon.app/setu/v2";

	if (argc < 2)
	{
		printf("usage: ./request url\n");
		exit(0);
	}

	if (argc < 3 || !strstr(argv[2], "-b"))
		system("chcp 65001");
	
	https_to_http(argv);
	printf("\n");
	start = clock();
	// while (request(argv[1], process_data)!=200);
	request(argv[1], process_data);
	// request(url, process_data);
	end = clock();

	printf("\n\nexecution time %f seconds\n", (end - start)/1000.0);

	return 0;
}