#include <iostream>
#include <string>

using namespace std;
int main () {
    string a, p, start;
    int i,j,k,l;
    int num;
    string b[100];
    j = 0;
    while (start != "ENDOFINPUT" ) {
        cin >> start;
        if (start == "ENDOFINPUT") {
            num = j;
            break;
        }
        if (start == "START") {
            getline(cin, p);
            getline(cin, p);
            num = p.length();
            for (i = 0; i < num; i++) {
                if (p[i] >= 'F' && p[i] <= 'Z') p[i] -= 5;
                else if (p[i] >= 'A' && p[i] <= 'E') p[i] += 21;  
            }
            b[j].assign(p);
            cin >> start;
            if (start == "END") {
                j++;
            }
        }   
    }
    for (j = 0; j < num; j++) {
        cout << b[j] << endl;
    }
    return 0;
}
