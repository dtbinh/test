#include <stdio.h>

int main () {
int *p;
p = (char *) malloc(sizeof(char) * 10 );
gets(p);
printf("%s",p);
}
