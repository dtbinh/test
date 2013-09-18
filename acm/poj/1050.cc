#include <iostream>
#include <stdlib.h>
using namespace std;

int count (int *a, int n, int m); 
int main () {
    int i, j, n;
    int *a;
    cin >> n ;
    a = (int *) malloc (sizeof(int) * n * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> *(a + i*n + j);
        }
    }
    int max1 = count (a , n, n);
    cout << max1 << endl;
    return 0;
}

int count (int *a, int n, int m) {
    int i, j, k ,l;
    int max1;
    int result1, result2;
    int sub1, sub2, sub3;
    int cat1 = 0, cat2 = 0;
    int center = n / 2;
    if (n == 0 || m == 0) return 0;
    if (n == 1 ) {
        max1 = -10000;
        for (i = 0; i < m; i++) {
            result1 = 0;
            for (j = i; j < m; j++) {
                result1 += *(a + j);
                max1 = max1 > result1 ? max1 : result1;
            }
        }
        return max1;
    }
    if (n > 1 ) {
        sub1 = count (a, center, m);
        sub2 = count (a + center * n, n - center, m);
        max1 = -10000;
        for (j = 0; j < m; j++) {
            for (l = j ; l < m; l++) {
                cat1 = -10000;
                cat2 = -10000;
                result1 = 0;
                result2 = 0;
                for (i = center - 1; i >= 0; i--) {
                    for (k = j; k <= l; k++) {
                        result1 += *(a + i * n + k);
                    }
                    cat1 = cat1 > result1 ? cat1 : result1;
                }

                for (i = center ; i < n; i++) {
                    for (k = j; k <= l; k++) {
                        result2 += *(a + i * n + k);
                    }
                    cat2 = cat2 > result2 ? cat2 : result2;
                }
                max1 = max1 > (cat1 + cat2) ? max1 : (cat1 + cat2) ;
            }
        }
        max1 = max1 > sub1 ? max1 : sub1 ;
        max1 = max1 > sub2 ? max1 : sub2 ;    
        return max1 ;
    }
}
