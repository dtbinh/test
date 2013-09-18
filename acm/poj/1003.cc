#include <iostream>
using namespace std;
int main () {
    int i,j,k, num;
    double l;
    double a[10],b[273];
    i = 0;
    num = 0;
    b[0] = 0.5;
    for (i = 1; i < 273; i++) {
        b[i] = b[i-1] + 1.0/(i*1.0 + 2.0);
    }
    i = 0;
    while ((cin >> l) != 0 ) {
        if (l == 0.00) break;
        a[i] = l;
        i++;
        num++;
    }
    
    //for (i = 0 ; i < 10;i++) {
    //    cout << a[i] << " " << b[i] << (a[i]>b[i]?1:0) <<endl;
    //}
    for (i = 0; i < num; i++) {
        for (j = 0; b[j] < a[i]; j++) {
        }
        cout << j+1 << " card(s) "<< endl;
    }
}
