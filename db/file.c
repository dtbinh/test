#include <stdio.h>

struct C {
    int a;
    char b ;
    double d ;
}; 
int main () {
    int a = 12345;
    char *b = "baimochen";
    char d1[20] = "wbmc";
    struct C *c = (struct C *) malloc (sizeof(struct C));
    c->a = 100;
    c->b = 'a';
    c->d = 100.00;
    FILE *fd = fopen ("./log","wb+");
    fwrite (&d1[0], sizeof(char), 20, fd);
    //fwrite (&a, sizeof(int), 1, fd);
   /* fwrite (&c->a, sizeof(int), 1, fd);
    fwrite (&c->b, sizeof(char), 1, fd);
    fwrite (&c->d, sizeof(double), 1, fd);
*/
    fclose(fd);
}
