#ifndef __DOMAIN__
#define __DOMAIN__

#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SOCKET_PATH "./my.sock"

#define ERR_EXIT(m)                                                            \
  do {                                                                         \
    perror(m);                                                                 \
    exit(-1);                                                                  \
  } while (0);

#endif // !__DOMAIN__
