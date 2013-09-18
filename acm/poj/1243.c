#include <stdio.h>

int dp[40][40], g, l;

int main () {
    for (int i = 0; i <= 30; i++) {
        dp[i][0] = i; dp[i][i] = (1 << i) - 1;
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <i; j++) {
            dp[i][j]= dp[i-1][j-1]+1+dp[i-1][j];
        }
    
    }

    int Case = 0;
    while (scanf("%d%d", &g, &l) && (g || l))
    {
        printf ("Case %d: ", ++Case);
        if (l > g) printf ("%d\n", dp[g][g]);
        else printf ("%d\n",dp[g][l]);
    }
    return 0;
}



