#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUFFER 1024
#define CONNECT_ADDR INADDR_ANY
#define CONNECT_PORT 3339
int main() {
  int socket_fd; // socket file descriptor
  struct sockaddr_in addr;
  char *message = "Hello";
  char respond[MAX_BUFFER];
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    return -1;
  }
  addr.sin_family = AF_INET;                  // IPv4
  addr.sin_addr.s_addr = htonl(CONNECT_ADDR); // the IP address of the server
  addr.sin_port = htons(CONNECT_PORT);        // the port number of the server
  if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }
  puts("[INFO]connected!\n");
  printf("[SEND]try to send message:%s\n", message);
  send(socket_fd, message, strlen(message), 0);
  size_t respond_len = recv(socket_fd, respond, sizeof(respond) - 1, 0);
  printf("[RECV]receive message:%s\n", respond);
  respond[respond_len] = '\0';
  close(socket_fd);
}