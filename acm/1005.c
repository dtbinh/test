#include <stdio.h>
#include <string.h>


int insert(char *c,int k,char *b,int *p) {
    int n = strlen(b)-1; //k是位置 ，b是字符串地址，p是价值,n为串末尾标记
    int i;
    for (i = n ; i >= k; i--) {
        *(b+i+1) = *(b+i);     
    }
    *(b+i) = *c;
    return *p;
}

int del(int k,char *b,int *p) {
    int n = strlen(b)-1;
    int i;
    for (i = k;i< n - 1;i++) {
        *(b+i) = *(b+i+1);
    }
    *(b+n) = '\0';
    return *p;
}

int change(char *c, int k, char *b, int *p) {
    *(b+k) =*c;
    return *p;
}

int main () {
char c[20];
gets(c);
char p = 'q';
int n = 5;
printf("%d",insert(&p,1,c,&n));
puts(c);

}
