#include <stdio.h>

int main () {
    int a;
    int a1;
    char d1[20];
    char *b;
    struct C *c;
    FILE *fd = fopen ("./log", "rb+");
    fread(d1, sizeof(char), 20, fd);
    //strcat (b, "");
    printf ("%s", d1);
    fclose(fd);
}
