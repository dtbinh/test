#include <stdio.h>

int main () {
    int t;
    scanf("%d",&t);
    int a1,b1;
    int a[1000],b[1000] ,c[1000],d[1000];
    int i;
    for (i = 0;i < t;i++) {
        scanf ("%d %d", &a[i], &b[i]);
        c[i] = 0;
        d[i] = 0;
    }
    
    for (i = 0; i < t; i++) {
        a1= a[i];
        b1 =b[i];
        while (a[i] != 0)
        {
        c[i] = c[i] + (a[i] & 1) ;
        a[i] = a[i] >> 1 ;
        };
        while (b[i] != 0)
        {
        d[i] = d[i] + (b[i] & 1) ;
        b[i] = b[i] >> 1 ;
        };
        if (c[i] < d[i])     printf("<\n");
        if (c[i] > d[i])     printf(">\n");
        if (c[i] == d[i])    {
            if (a1 == b1)   printf ("=\n");
            if (a1 < b1)    printf ("<\n");
            if (a1 > b1)    printf (">\n");
        }
    }

    return 0;    
}
