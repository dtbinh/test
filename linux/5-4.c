#include "apue.h"

int main (void) {
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf ("%s\n", tmpnam(NULL));
    tmpnam(name);
    printf ("%s\n", name);

    fp = tmpfile();
    fputs("one line of output\n", fp);
    rewind(fp);
    fgets(line, sizeof(line), fp);
    fputs(line, stdout);
}
