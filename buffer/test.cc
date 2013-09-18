#include <iostream>
#include <fstream>
#include <string.h>
#include "wbmc.info.pb.h"
using namespace std;

int main () {
    wbmc::Info msg;
    msg.set_qq(124760329);
    msg.set_name("baimochen");

    fstream output("info.txt", ios::out | ios::trunc | ios::binary);

    if (msg.SerializeToOstream(&output)) {
        cerr << "Failed" << endl;
        return -1;
    }
    return 0;
}
