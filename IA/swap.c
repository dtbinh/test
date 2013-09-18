#include <stdio.h> 
int swap (int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y ; 
	*y = temp ;

}

int main () {
int x, y;
x = 1;
y = 2;
swap (&x, &y);
}
