#include <stdio.h>

int main () {
    int num, n, m, i, j, k;
    int a[100],b[100],c[100];
    int max[1000];
    scanf ("%d",&num);
    for (i = 0; i< num && num <=1000 & num >= 1; i++) {
        scanf ("%d %d", &n, &m);
        if (n <= 9 || n > 100) return 1;
        for (j = 0;j < m && m < 1000;j++) {
            scanf ("%d %d %d", &a[j],&b[j],&c[j]);

            if (a[j] >100 || a[j] < 0) return 1;
            if (b[j] >100 || b[j] < 0) return 1;
            if (c[j] > b[j]) return 1;
        }
        




    }
}



