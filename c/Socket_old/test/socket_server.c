#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUFFER 1024
#define CONNECT_PORT 3339

int main() {
  int socket_fd, client_socket, valread;
  struct sockaddr_in address;
  char buffer[MAX_BUFFER] = {0};
  char *message = "Hello, client!";

  // 创建套接字
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    return -1;
  }

  // 准备地址结构
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(CONNECT_PORT);

  // 将套接字绑定到指定端口
  if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind");
    return -1;
  }

  // 监听连接
  if (listen(socket_fd, 1) < 0) {
    perror("listen");
    return -1;
  }

  puts("[INFO]Waiting for connections...");

  // 等待客户端连接
  client_socket = accept(socket_fd, NULL, NULL);
  if (client_socket < 0) {
    perror("accept");
    return -1;
  }

  // 从客户端接收消息
  valread = read(client_socket, buffer, sizeof(buffer));
  printf("[RECV]Received message from client: %s\n", buffer);

  // 发送回应消息给客户端
  send(client_socket, message, strlen(message), 0);
  printf("[SEND]Sent message to client: %s\n", message);

  close(client_socket);
  close(socket_fd);

  return 0;
}
