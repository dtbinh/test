/*服务端程序*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 4096


int main () {
    int sock;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(7777);
    char buf[4096];
    int nbyte, conn;

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

    /*监听*/
    if (listen(sock, 2) < 0) {
        printf("listened Error\n");
    } else {
        printf("Listened Success\n");
    }

    /*建立链接, 并输出信息*/
        if ((conn = accept(sock, (struct sockaddr*)NULL, NULL)) < 0) {
            printf ("Connected Error\n");
        } else {
            printf ("Connected Success %d\n", conn);
        }
        if ((nbyte = recv(conn, buf, MAXLINE, 0)) > 0) {
            buf[nbyte] = '\0';
            printf("byte length: %d\n%s\n", nbyte,buf);
                
        } else {
            printf ("Wrong return value:%d\n", nbyte);
        }
    close(sock);

}
