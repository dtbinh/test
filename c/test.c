#define PR(x, type) printf((#type), (x))
#define __t \
    int main () { \
        int c = 1; \
        PR(c , %d);\
    }\

__t


