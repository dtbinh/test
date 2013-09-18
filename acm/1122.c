#include <stdio.h>
#define NUM 30


int main () {
    int n,i,c;
    char *p ;
    scanf ("%d",&n);
    while((c = getchar()) != '\n');
    char *node[n];
    for (i = 0;i < n; i++) {
        p = (char *)malloc(sizeof(char)*30);
        node[i] = p ;
        while ((*p = getchar()) != '\n')  {
            if (*p == ' ') continue;
            p++;
        }
    }
    for (i = 0; i < n; i++ ) {
        p = node[i] ;
        while (*p != '\0') {
            putchar(*p);
            p++;
        }
    }
}

