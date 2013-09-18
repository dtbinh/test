#include <iostream>
#include <stdlib.h>
using namespace std;
int quick_sort (int *a, int i, int j) {
    int key = a[i] ;
    int left = i;
    int right = j;
    if (i == j) return 0;
    while (i != j) {
        while (j != i && a[j] >= key) {
            j--;
        }
        if (i != j && a[j] < key) {
        a[i] = a[j];
        }
        while (i != j && a[i] <= key) {
            i++;
        }
        if (i != j && a[i] > key) {
        a[j] = a[i];
        }
    }
    if (i == j) {
        a[i] = key;
        cout << left << " " << right << " " << i << endl;
        if ((i-1) > left) quick_sort (a, left, i-1);
        if ((i+1) < right )quick_sort (a, i+1 , right);
        return 0;
    }


}
int main ()  {
    int a[100] ;
    int i;
    srand(time(0));
    for (i = 0; i < 100;i++) {
        a[i] = rand()%200;
    }
    quick_sort (a, 0, 99);
    for (i = 0; i < 100; i++) {
        cout << a[i] << " " ;
    }
    return 0;
}
