#include "domain.h"
#include "sys/socket.h"
#include <string.h>
int main() {
  int socket_fd;
  char *buf = "hello";
  struct sockaddr_un servaddr;
  socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    ERR_EXIT("socket")
  }
  memset(&servaddr, 0, sizeof(struct sockaddr_un));
  servaddr.sun_family = AF_UNIX;
  strncpy(servaddr.sun_path, SOCKET_PATH, sizeof(servaddr.sun_path) - 1);
  if (connect(socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    ERR_EXIT("connect");
  }
  send(socket_fd, buf, strlen(buf), 0);
}
