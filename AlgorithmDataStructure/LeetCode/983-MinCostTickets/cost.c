

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int m_min(int a, int b) { return  a < b ? a : b;}
int dp(int i, int* days, int daysSize, int* costs, int* memo) {
    if (i >= daysSize) { return 0; }
    if (memo[i] != -1) { return memo[i];}
    
    memo[i] = INT_MAX;
    
    int durations[] = {1, 7, 30};
    int k = i;
    for (int j = 0; j < 3; j++) {
        while (k < daysSize && days[k] < days[i] + durations[j]) { k++; }
        memo[i] = m_min(memo[i], dp(k, days, daysSize, costs, memo) + costs[j]);
    }
    return memo[i];
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int *memo = (int *)malloc(sizeof(int) * daysSize);
    memset(memo, -1, sizeof(int) * daysSize);
    return dp(0, days, daysSize, costs, memo);
}

int main(int argc, const char * argv[]) {
    
    int days[] = {1,4,6,7,8,20}, costs[] = {2,7,15};
    int ans = mincostTickets(days, 6, costs, 3);
    printf("ans = %d\n", ans);
    
    return 0;
}
















