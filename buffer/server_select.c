/*服务端程序*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/select.h>

#define MAXLINE 4096

void str_cli(FILE *fd, int sockfdi, struct sockaddr_in addr);

int main () {
    int sock;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(7777);
    char buf[4096];
    int nbyte, conn;
    FILE *saveFile ;
    saveFile = fopen("./temp.txt", "w+") ; //保存文件

    /*创建socket描述符*/
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket initialized Error\n");
    } else {
        printf("socket initialized Success\n");
    }

    /*绑定地址*/
    if ((bind(sock, (struct sockaddr*)&addr,sizeof(addr))) < 0) {
        printf("binded Error\n");
    } else {
        printf("binded Success\n");
    }

    /*listen && accept*/
    listen(sock, 100);
    accept(sock, (struct sockaddr*)NULL, NULL);
    printf("accept\n");
    

    /*select 循环*/
    str_cli(saveFile, sock, addr);

}

void str_cli (FILE *fd, int sockfd, struct sockaddr_in addr) {
    int maxfd;
    fd_set rset;
    char buf[1024];
    int file_num = fileno(fd);

    FD_ZERO(&rset);
    for (;;) {
        FD_ZERO(&rset);
        FD_SET(file_num, &rset);
        FD_SET(sockfd, &rset);
        maxfd = fileno(fd)?sockfd:(fileno(fd) > sockfd) + 1;
        switch(select(maxfd, &rset, &rset, NULL, NULL)) {
            case -1: exit(-1); break;
            case 0 : break;
            default : {
                          if (FD_ISSET(sockfd , &rset)) {
                              recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)&addr, sizeof(addr));
                              if (FD_ISSET(fileno(fd), &rset)) {
                                  fwrite( buf, 256, 4, fd );
                                  printf("%s\n", buf);
                                  bzero(buf, sizeof(buf));
                              }
                          }       

                      }
        }
    }
    
    return 0;
}
