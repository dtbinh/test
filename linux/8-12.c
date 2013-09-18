#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int system (const char *cmdstring) {
    pid_t   pid;
    int     status;

    if (cmdstring == NULL) {
        return (1);

    }

    if ((pid = fork()) < 0) {
        status = -1;
    }
    else if (pid == 0) {
        execl ("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }
    else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }
    
    return (status);
}

int main (int argc, char **argv) {
    char buf[20] = "\0";
    int i;

    if (argc >= 2) {
        for (i = 1; i < argc-1; i++) {
            strcat (buf, argv[i]);
            strcat (buf, " ");
        }
        strcat (buf, argv[i]);
        printf ("%s\n", buf);
        system(buf);
        return 0;
    } 
    else {
        printf ("argument error!\n");
        return -1;
    }
}
