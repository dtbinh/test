#include <iostream>
using namespace std;

int main () {
    string result[100], a, b;
    int i, j, k, m, l1, l2, len1, len2, num1, num2, num3, num4, num5;
    int signal, mul;
    int x1[150] = {0}, x2[150] = {0}, x3[150] = {0};
    i = 0;
    l1 = 0;
    while (cin >> a >> b){
        if (cin.eof()) break;
        len1 = a.length(); //a chang du
        len2 = b.length(); //string b length
        signal = 0;
        if (len2 == 1) num2 = b[0] - '0';
        if (len2 == 2) {
            num2 = b[1] - '0'; 
            num2 += (b[0] - '0') * 10; // num2 是第二个数字
        }
        i = len1 - 1; 
        while (a[i] == '0') i--;
        num1 = 0;
        num3 = 0;
        j = 149;
        for (; i >= 0; i--,j--) {
            if (a[i] != '.' && signal != 1) num1++; //num1是第一个小数点后有几位
            if (a[i] == '.') {
                signal = 1;
                if (i == 0) break ;
                i--;
            } 
            if (a[i] != '.' ) {
                x1[j] = a[i] - '0';
                x2[j] = a[i] - '0';
                num3++;  //num3有效数字个数
            }
        }
        num4 = num3 ; 
        signal = 0;
        if (num2 > 1) {
            for (k = 2; k <= num2; k++) {
                if (signal == 0) {
                    for (j = 149; j > 149 - num3 ; j--) {
                        for (i = 149, m = j; i > 149 - num4; i--, m--) {
                            mul = x1[j] * x2[i];
                            x3[m - 1] = x3[m - 1] + (mul + x3[m])/10;
                            x3[m] = (mul + x3[m]) % 10 ;
                        }
                    }
                    while (x3[m] == 0) m++ ;
                    num4 = 149 - m + 1 ;
                    signal = 1; 
                    for (i = 0; i < 150; i++) x2[i] = 0;
                    continue ;
                }
                if (signal == 1) {
                    for (j = 149; j > 149 - num3 ; j--) {
                        for (i = 149, m = j; i > 149 - num4; i--, m--) {
                            mul = x1[j] * x3[i];
                            x2[m - 1] = x2[m - 1] + (mul + x2[m])/10;
                            x2[m] = (mul + x2[m]) % 10 ;
                        }
                    }
                    while (x2[m] == 0) m++ ;
                    num4 = 149 - m + 1;
                    signal = 0;
                    for (i = 0; i < 150; i++) x3[i] = 0;
                    continue ;
                }
            }

            l2 = num2*num1;
            num5 = 149 - l2 + 1;
            if (num5 < m ) m = num5;
            for (k = m; k < 150; k++) {
                if (k == (149 - l2 + 1)) {
                    result[l1] += '.';
                } 
                if (signal == 0) {
                    result[l1] += x2[k] + '0';
                }
                else {
                    result[l1] += x3[k] + '0';
                }
            }
        }
        if (num2 == 0) {
            result[l1] += '1';
        }
        if (num2 == 1) {
            k = 0;
            signal = 0;
            while (a[k] == '0') {
                k++;
            }
            i = k;
            k = len1 - 1;
            while (a[k] == '0') {
                k--;
            }
            if (i == k) {
                if (a[i] != '.') {
                    while (i <= len1 - 1) {
                        result[l1] += a[i];
                        i++;
                    }
                }
            }
            if (a[k] == '.') k--; 
            while (i <= k) {
                result[l1] += a[i];
                i++;
            }
            if (result[l1].length() == 1) {
                if (result[l1][0] == '0' || result[l1][0] == '.')
                    result[l1].assign("0");
            }
            if (result[l1].length() == 0) {
                result[l1].assign("0");
            }

        }
        for (i = 0; i < 150; i++) {
            x1[i] = 0;
            x2[i] = 0;
            x3[i] = 0;
        }
        l1++;
        signal = 0;
    }
    i = 0;
    while (i < l1  ) {
        cout << result[i] << endl;
        i++;
    }
}


