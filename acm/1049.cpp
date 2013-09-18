#include <string>
#include <iostream>
using namespace std;

bool IsEvent(string bigInt){
    int sum = 0;
    for (size_t i=0; i < bigInt.size(); ++i)
    {
        sum += (bigInt[i]-'0');
    }
    return (sum % 3) == 0;
}

int main () {
    int T;
    string bigInt;
    struct {
    string LM;
    }a[10000];
    cin >> T;
    for (int i = 0; i < T; i++  ){
        cin >> bigInt;
        a[i].LM = (IsEvent(bigInt) ? "YES" : "NO") ;
    }
    for (int j = 0; j < T; j++) {
        cout << a[j].LM <<endl;
    }
    return 0;
}
