#include <stdio.h>


int main () {
    int n,m;
    int i,j;
    int a[22][22], b[22][22];
	int i1[20],j1[20],k[20];
	int q = 0;
    while (1) {
    scanf ("%d %d", &n, &m);
    if (n == 0 && m ==0 ) goto L;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 22; j++) { 
                a[i][j] = 0;
                b[i][j] = 0;
            }
    }
        for (i = 1;i < n+1;i++) {
        for (j = 1;j < m+1;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for ( i = 1; i < n+1; i++){
        for (j = 1;j < m+1; j++) {
            if (a[i+1][j] != 0 && bijiao(a[i+1][j],a[i][j]) == 1)    {
                b[i][j] += a[i+1][j];
            }
            if (a[i-1][j] != 0 && bijiao(a[i-1][j],a[i][j]) == 1)    {
                b[i][j] += a[i-1][j];
            }
            if (a[i][j+1] != 0 && bijiao(a[i][j+1],a[i][j]) == 1)    {
                b[i][j] += a[i][j+1];
            }
            if (a[i][j-1] != 0 && bijiao(a[i][j-1],a[i][j]) == 1)    {
                b[i][j] += a[i][j-1];
            }
           if( b[i][j] < 0) b[i][j]=b[i][j]*(-1);
        }   
    }
     k[q] = a[1][1];
     i1[q] = 1;
     j1[q] = 1;
        for (i = 1;i < n+1;i++) {
            for (j = 1;j < m+1;j++) {
             if (b[i][j] > k[q] ) {
                k[q] = b[i][j];
                i1[q] = i;
                j1[q] = j;

        }
             }
        }
		q++;
    }
L:i = 0;
	while (i != q) {
	printf ("%d %d %d\n",i1[i],j1[i],k[i]);
    i++;
}
}

int bijiao (int a , int b) {
    if (a>0 && b< 0) return 1;
    if (a < 0 && b> 0) return 1;
}
