#include <stdio.h>
#include <string.h>



int main () {
    int t, n, m;
    int i,j,k,l,i1;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    scanf("%d", &t);
    char** a;
    char** b; 
    char* c,*p;
    char*** d;
    d = (char ***) malloc (sizeof(char**) * t);
    p = (char *) malloc(sizeof(char) * 20);
    for (i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        a = (char **) malloc (sizeof(char*) * m);
        b = (char **) malloc (sizeof(char*) * m);
        *(d+i) = (char **) malloc (sizeof(char*) * 40);
        c = (char *) malloc (sizeof(char) * 100);
        for (j = 0; j < m; j++) {
            *(a+j) = (char *) malloc (sizeof(char) * 20);
            *(b+j) = (char *) malloc (sizeof(char) * 20);
        }
        for (j = 0; j < m; j++) {
            scanf ("%s %s", *(a + j), *(b + j));
        }
        //for (j = 0; j < m; j++) {
        //    printf ("%s %s\n",*(a+j), *(b+j));
        //}
        //getchar(c);
        gets(c);
        gets(c);
        j = 0;
        l = 0;
        k = 0;
        while (*(c+k) != '\0'){
            if (*(c+k) == ' '  ) {
                j = 0;
                *(*(d+i)+l) = (char *) malloc (sizeof(char) * 20);
                //printf("%s", p);
                strcpy(*(*(d+i) + l) , p);
                //printf(*(*(d+i) + l) , p);
                l++;
                k++;
                continue;
            }

            *(p+j) = *(c+k);
            j++;
            k++;
            if(*(c+k) == '\0') {
                j = 0;
                *(*(d+i)+l) = (char *) malloc (sizeof(char) * 20);
                printf("%s", p);
                strcpy(*(*(d+i)+l), p);
                //printf(*(*(d+i) + l) , p);
                continue;
            }
        }
        l = l + 1;
        for (j = 0; j < n;j++) {
            for (i1 = 0; i1 < l;i1++) {
                for (k = 0;k < m;k++) {
                    if (strcmp(*(a+k), *(*(d+i)+i1)) == 0) {    
                        strcpy(*(*(d+i)+i1), *(b+k));
                    }
                }
            }
        }
        


        for (k = 0; k < m ; k++) {
            free((void *)*(a+k));
            free((void *)*(b+k));
        }
        free ((void *)a);
        free ((void *)b);
        free ((void *)c);
    }

    for (i = 0; i < t; i++) {
        for (j = 0; j < 1; j++ ) {
            printf ("%s",*(*(d+i) + j));
            printf (" ");
        }
    }


    free((void *)p);
}
