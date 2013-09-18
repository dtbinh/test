//一个长度为2n的（整型）数组元素为 a1 a2 ... an b1 b2 ... bn 要求： 用O(1)的空间代价, 在O(n)时间内把数组变成 a1 b1 a2 b2 a3 b3 ... an bn
//
//
//

#include <stdio.h>


int main (int argc,int argv[]) {
    if (argc != 2)
        exit (EXIT_FAILURE);
    int N = argv[1];
    int a[2 * N];
    int temp;
    for (int i = 0; i < 2*N; i++) {
        a[i] = i;
    }
    
    for (int i = N ; i )


}


