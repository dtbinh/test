#include "apue.h"

int main (void) {
    char    *ptr;
    int     size;

    if (chdir("/usr/include/GNUstep/Cocoa/") < 0)
        err_sys("chdir failed");

    ptr = (char *) malloc (sizeof(char) * 100);
    if (getcwd(ptr, size) == NULL) 
        err_sys("getcwd failed");

    printf ("cwd = %s\n", ptr);
    exit(0);
}
