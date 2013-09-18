#include <iostream>
using namespace std;

int main () {
    double i,j,k;
    j = 0.0;
    for (i = 0; i < 12; i++) {
        cin >> k;
        j += k;
    }

    cout << "$" <<j/12 << endl;

}
