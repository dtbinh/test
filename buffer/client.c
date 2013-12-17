#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>

int main (int argc, char **argv) {
    int sock;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.
}
