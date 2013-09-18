#include <iostream>
using namespace std;
int funD (int a[], int left, int right);

int main () {
    int a[50000];
    int num1, num2;
    int i = 0, j = 0;
    cin >> num1;
    int b[num1];
    int max1, max2, sum;
    for (j = 0;j <num1; j++) {
        cin >> num2;
        i = 0;
        sum = 0;
        while (i < num2) {
            cin >> a[i];
            i++;
        }
        for (i = 0; i < num2 - 1; i++) {
            max1 = funD(a, 0, i);
            max2 = funD(a, i + 1, num2 - 1);
            if (sum <= (max1 + max2)) {
                sum = max1 + max2;
            }
        }
        b[j] = sum;
    }
    for (j = 0; j < num1; j++) {
        cout << b[j] << endl;
    }

}
int funD(int a[], int left, int right) {
    int max; 
    int i;
    if (left == right) {
        return a[left];
    }

    int center = (left + right)/2 ; 
    int sumSubLeft = funD(a, left, center);
    int sumSubRight = funD(a, center + 1, right);
    int cLeft = 0, rLeft = 0;
    for (i = center; i >= left; i--) {
        rLeft += a[i];
        if (rLeft > cLeft) {
            cLeft = rLeft;
        }
    }
    int cRight = 0, rRight = 0;
    for (i = center + 1; i <= right; i++) {
        rRight += a[i];
        if (rRight > cRight) {
            cRight = rRight;
        }
    }
    
    max = (cRight + cLeft) > sumSubLeft ? (cRight + cLeft) : sumSubLeft;
    max = max > sumSubRight ? max : sumSubRight;
    return max;
}
