
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 动态规划
 n = 10
 dp[10] = dp[10] + dp[0] = 0 + 1
 
 dp[5] = dp[5] + dp[5-5] = 0 + 1
 dp[6] = dp[6] + dp[6-5] = 0 + 0
 dp[7] = dp[7] + dp[7-5] = 0 + 0
 dp[8] = dp[8] + dp[8-5] = 0 + 0
 dp[9] = dp[9] + dp[9-5] = 0 + 0
 dp[10] = dp[10] + dp[10-5] = 1 + 1
 
 dp[1] = dp[1] + dp[1-1] = 0 + 1
 dp[2] = dp[2] + dp[2-1] = 0 + 1
 dp[3] = dp[3] + dp[3-1] = 0 + 1
 dp[4] = dp[4] + dp[4-1] = 0 + 1
 dp[5] = dp[5] + dp[5-1] = 1 + 1
 dp[6] = dp[6] + dp[6-1] = 0 + 2
 dp[7] = dp[7] + dp[7-1] = 0 + 2
 dp[8] = dp[8] + dp[8-1] = 0 + 2
 dp[9] = dp[9] + dp[9-1] = 0 + 2
 dp[10] = dp[10] + dp[10-1] = 2 + 2
 */

/**
 n=3
 dp[3] = dp[3] + dp[3-1] = 0 + 0
 
 dp[1] = dp[1] + dp[1-1] = 0 + 1
 dp[2] = dp[2] + dp[2-1] = 0 + 1
 dp[3] = dp[3] + dp[3-1] = 0 + 1
 */
int waysToChange(int n){
    if (n < 2) { return n; }
    
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    
    int coins[] = {25,10,5,1};
    
    for (int i = 0; i < 4; i++) {
        int c = coins[i];
        for (int j = c; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - c]) % 1000000007;
        }
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
    
    printf("ans = %d\n", waysToChange(10));
    
    return 0;
}









