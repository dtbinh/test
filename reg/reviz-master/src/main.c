#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nfa.h"
#include "dfa.h"

/* Compile basic regular expression to NFA */
struct NFA reg_to_NFA(const char *regexp);

/* Convert an NFA to DFA, this function returns the start state of the
 * resulting DFA */
struct DFA_state *NFA_to_DFA(const struct NFA *nfa);

/* Simplify DFA by merging undistinguishable states */
struct DFA_state *DFA_optimize(const struct DFA_state *dfa);


int main(int argc, char *argv[])
{
    struct NFA nfa;
    struct DFA_state *dfa, *dfa_opt;
    char *p;
    FILE *fp_nfa, *fp_dfa, *fp_dfa_opt;
    p = (char *) malloc (sizeof(char) * 1000);
    char *a = *(argv + 1);
    int i, j, l, k;
    int length1, length2 = 0;

    for (j = 0; j < 1000; j++) {
        *(p + j) = '\0';
    }
    if (argc == 2)
    {
        if ( (fp_nfa = fopen("nfa.dot", "w")) == NULL) {
            perror("fopen nfa.dot error"); exit(-1);
        }
        if ( (fp_dfa = fopen("dfa.dot", "w")) == NULL) {
            perror("fopen dfa.dot error"); exit(-1);
        }
        if ( (fp_dfa_opt = fopen("dfa_opt.dot", "w")) == NULL) {
            perror("fopen dfa_opt.dot error"); exit(-1);
        }

        fprintf(stderr, "regexp: %s\n", argv[1]);  

        /* A =(....) {num }*/
    /*    i = 0;
        for (; *(*(argv + 1)  + i) != NULL; i++) {
            if (*(*(argv + 1) + i) == '}' && i != length2) {
                int num1 = 1, num2 = 0;
                i--;
                length2 = i;
                while (*(*(argv + 1) + i) != '{') { 
                    num2 += num1 * (*(*(argv + 1) + i) - '0');
                    num1 *= 10;
                    i--;
                } // i = {
                if (*(*(argv + 1) + i - 1) == ')') {
                    num1 = 0;
                    j = i - 1; // j = .)
                    if (*(*(argv + 1) + j) == '(') 
                        return -1;
                    while (*(*(argv + 1) + j) != '(' ) {
                        j--;        // j = (
                    }
                    num1 = i - j + 1; //content ()'s  number
                    char *b = (char *) malloc (sizeof(char) * num1);
                    j++; // j = (.
                    *b = '(';
                    for (k = 1; *(*(argv + 1) + j) != ')'; j++, k++) {
                        *(b + k) = *(*(argv + 1) + j);        
                    }
                    for (;*(*(argv + 1) + j) != '(';) {
                        j--;
                    } // j = ( 
                    *(b + k ) = ')';
                    *(b + k + 1) = '\0';    //k = length
                    for (k = length1; k <= j - 1; k++) {
                        *(p + k) = *(*(argv + 1) + k);
                    }      //k = (

                    for (j = 0; j < num2; j++) {
                        for(l = 0;*(b + l) != NULL; l++,k++ ) {
                            *(p + k) = *(b + l);
                        }
                    }//k = ).
                    j = 0;
                    while (*(*(argv + 1) + j) != '}')
                        j++;
                    j++;// j = }.
                    for (;*(*(argv + 1) + j) != NULL; j++, k++) {
                        *(p + k) = *(*(argv + 1) + j);
                    }
                    *(p + k ) = NULL;
                    length1 = k;
                    a = p;
                    continue;
            }

            for (j = 0; j != i; j++) {
                *(p + j) = *(*(argv + 1) + j);
            }   
            for (; j < num2 + i; j++) {
                *(p + j) = *(*(argv + 1) + i - 1);
            }
            while(*(*(argv + 1) + i) != '}')
                i++;
            i++; 
            for (; *(*(argv + 1) + i) != NULL; i++, j++) {
                *(p + j) = *(*(argv + 1) + i); 
            }
            a = p ;
        }

    } */


    /* parse regexp and generate NFA and DFA */
    nfa = reg_to_NFA(a);
    dfa = NFA_to_DFA(&nfa);
    dfa_opt = DFA_optimize(dfa);

    /* dump NFA and DFA as graphviz code */
    NFA_dump_graphviz_code(&nfa, fp_nfa);
    DFA_dump_graphviz_code(dfa, fp_dfa);
    DFA_dump_graphviz_code(dfa_opt, fp_dfa_opt);

    /* finalize */
    NFA_dispose(&nfa);    fclose(fp_nfa);
    DFA_dispose(dfa);     fclose(fp_dfa);
    DFA_dispose(dfa_opt); fclose(fp_dfa_opt);
}
else {
    printf("usage: %s 'regexp'\n", argv[0]);
}

return 0;
}
