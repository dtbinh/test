#include <stdio.h>
#include <string.h>

char *multiply (char *a, char *b,int len_a, int len_b) {
    int i, j , k, mul;
    int a1[len_a], b1[len_b] ;
    int p [101] ;
    char *p1 = (char *) malloc (sizeof(char)*101);
    *(p1+100) = '\0' ;
    k = 0;
    for (i = 0; i < 101; i++) {
        *(p + i) = 0;
    }
    for (i = len_a - 1; i >= 0 ; i--) {
        *(a1 + i) =*(a + i) - '0';
    }
    for (i = len_b - 1; i >= 0 ; i--) {
        *(b1 + i) =*(b + i) - '0';
    }
    for (i = len_a - 1; i >= 0; i--){
        for (j = len_b - 1, k = 100 - len_a + i; j >= 0; j--, k--) {
            mul = *(a1 + i) * *( b1 + j);
            *(p + k - 1) = (mul + *(p + k))/ 10 + *(p + k - 1) ;
            *(p + k) = (mul + *(p + k))% 10 ;
        }
    }
    *(p1 - k - 2) = '0';
    while (*(p + k) == 0) k++;
    i = k ;
    while (k != 100) {
        *(p1 + k) = *(p + k) + '0' ;
        printf ("%d",*(p + k)) ;
        k++;
    }
    return p1 + i;
}



int main () {
    char *a = (char *) malloc (sizeof(char) * 100) ;
    char *b = (char *) malloc (sizeof(char) * 100) ;
    scanf ("%s", a);
    scanf ("%s", b);
    char *p = multiply (a, b, strlen(a), strlen(b));
    free (a);
    free (b);
    //free ((void *)p);
    return 0;
}
