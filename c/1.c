#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {

    char *a = (char *)malloc(sizeof(char) * 10);
    int fd = open("./op.txt", O_WRONLY);
    void *b = mmap(a, 10, PROT_EXEC|PROT_READ|PROT_WRITE|PROT_NONE, MAP_SHARED,fd, 0);
    ((char *)b)[5] = 'w';
    munmap(b, 10);
    close(fd);
}
