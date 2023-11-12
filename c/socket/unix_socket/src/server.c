#include "domain.h"
int main(int argc, char *argv[]) {
  int socket_fd, connected_fd;
  struct sockaddr_un addr;
  size_t numRead;
  char buf[BUF_SIZE]={0};
  socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd < 0)
    ERR_EXIT("socket");
  if (remove(SOCKET_PATH) < 0 && errno != ENOENT) {
    ERR_EXIT("remove");
  }
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);
  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) <
      0) {
    ERR_EXIT("bind");
  }
  if (listen(socket_fd, 100)) {
    ERR_EXIT("listen");
  }
  for (;;) {
    connected_fd = accept(socket_fd, NULL, NULL);
    if (connected_fd < 0) {
      ERR_EXIT("accept");
    }
    while ((numRead = read(connected_fd, buf, BUF_SIZE)) > 0) {
      write(STDOUT_FILENO, buf, BUF_SIZE);
    }
  }
  return EXIT_SUCCESS;
}
