#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define BACKLOG 5


int main () {
    struct sockaddr_in srvaddr, clientaddr;
    char buf[1024];
    int nbytes;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        exit(1);
    }
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(1234);
    if (inet_aton("127.0.0.1", srvaddr.sin_addr.s_addr) == -1)
        exit(1);
    if (bind(sockfd, (struct sockaddr*)&srvaddr, sizeof(struct sockaddr)) == -1 ) {
        exit(1);
    }
    if (listen(sockfd, BACKLOG) == -1) {
        exit(1);
    }
    int sin_size = sizeof(struct sockaddr_in);
    int new_fd = accept (sockfd, (struct sockaddr*)&clientaddr, &sin_size);
    nbytes = read (sockfd, buf, 1024);
    printf ("client: %s\n", buf);
    

}
