#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main () {
    struct a {
        int a;
        char c[];
    } b ;

    b.c = "a";
}
