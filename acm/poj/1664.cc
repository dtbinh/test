#include <iostream>
using namespace std;
int fn (int m, int n);


int main () {
    int i, m, n, t;
    cin >> t;
    int result[t];
    i = t;
    while (t > 0) {
        cin >> m >> n ;
        result[t] = fn (m, n);
        t--;
    }
    while (i > 0) {
        cout << result[i] << endl;
        i--;
    }
    return 0; 
}
int fn(int m, int n) {
    if (m < 0) 
        return 0;
    if (m == 0|| n == 1)
        return 1;
    return fn(m-n, n) + fn(m, n - 1);
}
