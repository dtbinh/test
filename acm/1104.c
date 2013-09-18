#include <stdio.h>

char *tiqu1(char *head) {
    char *p1;
    int i = 0;
    p1 = head;
    if (*p1 == ':' && *(p1+1) == '/' && * (p1 +2) == '/') {
        p1 = p1 + 3;
        return p1;
    }
    return tiqu1(p1 + 1);
}

int tiqu2 (char *head) {
    char *p1;
    p1 = head;
    if (*p1 == '/') {
        *p1 = '\0';
        return 1;

    }
    if (*p1 == ':') {
        *p1 = '\0';
        return 1;
    }    
    tiqu2(p1 + 1);
    return 1;
}

char * tiqu (char * head) {
    char *p1;
    p1 = tiqu1(head);
    tiqu2(p1);
    return p1;
}

int main () {
    int num,i;
    char *add[100];
    scanf ("%d", &num);
    for (i = 0; i < num; i++) {
        *(add + i) = (char *) malloc (sizeof(char)*1000);
        scanf ("%s", *(add + i));
        *(add + i) = tiqu(*(add + i));
        printf ("%s\n", *(add + i));
    }
    

}
