#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>

int main (int argc, char **argv) {
    int sock, nbyte, ret;
    char recvline[4096];
    char sendline[4096];
    struct sockaddr_in addr;
    
    /*输入参数判断*/
    if (argc != 3) {
        printf("Input Error!\nusage: ./client <Ip Address> <msg>\n");
        exit(0);
    }
    
    /*socket 描述符*/
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf ("Socket Initialized Error\n", strerror(errno), errno);
        exit(0);
    }
    /*地址设定*/
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7777);
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) < 0) {
        printf ("inet_pton Error for %s", argv[1]);
        exit(0);
    }


    /*连接远程*/
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("connected Error: %s (errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    /*发送消息*/
    strcpy (sendline,"Hello World");
    if ((ret = send(sock, sendline, strlen(sendline), 0)) < 0) {
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    } else {
        printf("%d\n", ret);
    }

    close(sock);
    exit(0);
}
