/*
#include<iostream>
using namespace std;
int main()
{
int a[32][32],i,j,k,p,n;
p=1;
while(p==1)
{
cout<<"Enter n(n=1~25):";
cin>>n;
if((n!=0)&&(n<=25)&&(n%2!=0))
p=0;
}
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[i][j]=0;
j=n/2+1;
a[1][j]=1;
for(k=2;k<=n*n;k++)
{
i=i-1;
j=j+1;
if((i<1)&&(j>n))
{
i=i+2;
j=j-1;
}
else 
{
if(i<1)
i=n;
if(j>n)
j=1;
}
if(a[i][j]==0)
a[i][j]=k;
else 
{
i=i+2;
j=j-1;
a[i][j]=k;
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}

}*/
#include <stdio.h>


int main () {
	int n,i,j,k,central;
	int x;
	int y;
	scanf( "%d", &n);
	int a[21][21];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++ ) {
			a[i][j] = 0 ;
		}


	}
	central = (n + 1)/2;
	a[1][central] = 1 ;
	x = 1 ;
	y = central ;
	for (k = 2; k <= n*n; k++) {
        if (a[x][y] == 0 ) goto L;
		if (a[x][y] != 0 && (x == 1 || y == n)) {

			if (x == 1 && y < n) { 
				x = n;
				y++;  
				goto L;
			}  

			if (x > 1 && y == n) {
				x--;
				y = 1;
				goto L;
			}

			if (x = 1 && y == n) {

				x++;
				goto L;
			}
		}
	  if (a[x][y] != 0 && a[x-1][y+1] ==0 ) {
		  x--;
		  y++;
		  goto L;
	  }
      if (a[x][y] != 0 && a[x-1][y+1] != 0 ) {
	     x++;
		 goto L;
	  }

L:   a[x][y] = k ;

}

	for (i = 1; i <= n; i++) {
		for (j = 1;j <= n; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");	


	}


}
