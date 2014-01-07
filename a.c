#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

typedef struct Pair {
    int left;
    int right;
} pair;


void __pair__out(pair *p) {
    printf ("%d %d\n", p->left, p->right);
}

pair * __pair__init() {
    pair *p = (pair *) malloc(sizeof(struct Pair));
    p->left = 0;
    p->right = 0;
    return p;
}

int main () {
    int num;
    int i;
    scanf("%d", &num);
    pair *head[num];
    for (i = 0; i < num; i++) {
        head[i] = __pair__init();
    }
    for (i = 0; i < num; i++) {
        __pair__out(head[i]); 
    }



}
