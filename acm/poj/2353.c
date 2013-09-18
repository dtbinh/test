#include <stdio.h>
struct point {
    int x;
    int y;
} c[100][500];
int main () {
    int i, j, k, l, m ,n;
    int resultX, resultY;
    int a[100][500], b[100][500], d[50000];
    int min = 2000000000;

    scanf ("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf ("%d", &a[i][j]);
        }
    }
    for (j = 0; j < n; j++) {
        b[0][j] = a[0][j];
        c[0][j].y = 0;
        c[0][j].x = j;
    }
    for (i = 1; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = b[i-1][j] + a[i][j];
            c[i][j].x = j;
            c[i][j].y = i - 1;
        }
        for (j = 1; j < n; j++) {
            k = b[i][j-1] + a[i][j];
            if (k < b[i][j]) {
                b[i][j] = k;
                c[i][j].x = j - 1;
                c[i][j].y = i;
            }
        }
        for (j = n - 2; j >= 0; j-- ) {
            k = b[i][j+1] + a[i][j];
            if (k < b[i][j]) {
                b[i][j] = k;
                c[i][j].x = j + 1;
                c[i][j].y = i; 
            }
        }
    }
    for (j = 0; j < n; j++) {
        if (min > b[m-1][j]) {
            min = b[m-1][j];
            resultX = j;
        }
    }
    resultY = m - 1;
    l = 1;
    while (resultY >= 0) {
        d[l++] = resultX + 1;
        if (resultY == 0) break;
        j = resultX, i = resultY;
        resultX = c[i][j].x;
        resultY = c[i][j].y;
    }
    while (--l) {
        printf ("%d\n", d[l]);
    }
    return 0;

}
