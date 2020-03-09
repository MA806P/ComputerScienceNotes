
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

//方法一，画个树方便理解，每次都减去，一层层的递归
int backtrack(int* coins, int coinsSize, int amount, int *count) {
    if (amount < 0) { return -1; }
    if (amount == 0) { return 0; }
    if (count[amount - 1] != 0) return count[amount - 1];
    int min = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
        printf("amount = %d, coin[%d] = %d\n", amount,i, coins[i]);
        int res = backtrack(coins, coinsSize, amount - coins[i], count);
        printf("res = %d, min = %d\n", res, min);
        if (res >= 0 && res < min) {
            //这个 res<min 是找到最少的组合 6 = 1+1+1+1+1+1 2+2+2 3+3
            min = 1 + res;
        }
    }
    count[amount - 1] = min == INT_MAX ? -1 : min;
    for (int i = 0; i < amount; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");
    return count[amount - 1];
}


int coinChange0(int* coins, int coinsSize, int amount){
    if (amount < 1) { return 0; }
    //用好保存，计算过的值，防止后面重复计算费时
    int *count = (int *)malloc(sizeof(int)*amount);
    for (int i = 0; i < amount; i++) {
        count[i] = 0;
    }
    return backtrack(coins, coinsSize, amount, count);
}


//方法二、动态规划
int coinChange(int* coins, int coinsSize, int amount){
    if (amount < 1) { return 0; }
    int max = amount + 1;
    
    //dp 初始值为最大值
    int *dp = (int *)malloc(sizeof(int)*max);
    dp[0] = 0;
    for (int i = 1; i < max; i++) {
        dp[i] = max;
    }
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                int temp = dp[i - coins[j]] + 1;
                dp[i] = dp[i] < temp ? dp[i] : temp;
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main(int argc, const char * argv[]) {
    
    int coins[] = {1,2,3};
    int a = coinChange(coins, 3, 6);
    printf("=== %d\n", a);
    return 0;
}




