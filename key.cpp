#include <stdio.h>
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main () {
    string str;
    while (cin >> str) {
        bitset<8> val(str);
        cout<<hex<<val.to_ulong();
    }
    cout<<endl;
    return 0;
}
