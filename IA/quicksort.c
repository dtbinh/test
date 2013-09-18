#include <stdio.h>
int quicksort (int *a, int p, int r) {
	int q;
	if (p < r) {
		q = partion (a, p, r);
		quicksort (a, p, q - 1);
		quicksort (a, q + 1, r);
	}
}

int exchange (int *x, int  *y) {
	int temp;
	temp = *x ;
	*x = *y ;
	*y = temp ;
}

int partion (int *a, int p, int r) {
	int x, i ,j;
	x = a [r];
	i = p - 1;
	for (j = p ; j < r; j++) {
		if (a[j] <= x) {
			i = i + 1;
			exchange (&a[i], &a[j] );
		}
	}
	i = i + 1; 
	exchange (&a[r],&a[i]);
	return i;

}

int main () {
	int i, p, q, num;
	int a[100];
	scanf ("%d %d %d", &num, &p ,&q);
	  --p;
	  --q;
	  for (i = 0; i < num; i++) {
	  scanf ("%d", &a[i]);
	  }
	/*a[0] = 2; a[1] = 8; a[2] = 7; a[3] = 1; a[4] = 3; a[5] =5; a[6]= 6;a[7] =4;*/
	quicksort(a, p, q );

	for (i = p; i <= q; i++) {
	  printf ("%d ", a[i]);
	  }
}
