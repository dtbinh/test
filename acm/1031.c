#include <stdio.h> 

void main () {
	int t,i,j,temp;
	struct {
		int num;
		int n[101];
		int a;
		int b;
		int result;
	} data[100];
	scanf ("%d",&t);
	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &data[i].num, &data[i].a, &data[i].b);
		for (j = 1; j < data[i].num; j++) 
		  scanf ("%d", &data[i].n[j]);
		if (data[i].a < data [i].b)  {
			temp = data[i].a ;
			data[i].a = data[i].b;
			data[i].b = temp ;
		}
		if ( data[i].a > data[i].b)  {
			for (j = data[i].b ;j< data[i].a; j++) {
				data[i].result = data[i].result + data[i].n[j];
			}
		} 
	}

	for (i = 0;i < t; i++ ) printf ("%d\n",data[i].result);


}
