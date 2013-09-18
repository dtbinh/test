#include <stdio.h>

int main () {
int a[100],b[100];
int a1,b1;
int num;
int i,j,k;

scanf ("%d",&num);
for (i = 0; i < num; i++) {
    scanf("%d %d",&a[i],&b[i]);
}
for (i = 0;i < num ; i++) {
    j = a[i];
    k = b[i];
    a1 =0 ;
    b1 =0 ;
    while (a[i] != 0) {
        a1 = a1 + (a[i] & 1);
        a[i] = a[i] >> 1;
    }
    while (b[i] != 0) {
        b1 = b1 + (b[i] & 1);
        b[i] = b[i] >> 1;
    }

    if (a1 < b1) printf ("<\n");
    if (a1 > b1) printf (">\n");
    if (a1 == b1) {
        if (j == k) printf ("=\n");
        if (j < k)  printf ("<\n");
        if (j > k)  printf (">\n");
    }
}
}
