
#include <stdio.h>

//暴力解法，遍历所有情况，找到差值最大
int maxProfit0(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 1) { return 0; }
    
    int max = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int temp = prices[j] - prices[i];
            if (temp > 0 && temp > max) {
                max = temp;
            }
        }
    }
    return max;
}

//遍历一遍，找到最小值，顺便找到最大差值
int maxProfit1(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 1) { return 0; }
    
    int max = 0, minPrice = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (minPrice > prices[i]) {
            minPrice = prices[i];
        } else {
            int temp = prices[i] - minPrice;
            max = max < temp ? temp : max;
        }
    }
    return max;
}


/*
7  1  5  3  6  4
0  0  4  2  5  3
 
 7  4  8  6  9  2  1  3  9
 0  0  4  2  5  0  0  2  8
 4 = 8 - 4
 2 = 6 - 4
 5 = 9 - 4
 2 = 3 - 1
 8 = 9 - 1
 
 max(0, profit + p[i] - p [i-1])
 p[i] - p[i-1] + p[i-1] - p[i-2] = p[i] - p[i-2]
 其实就是求得，当前值与之前所有的差最大值
 
 区间和可以转换成求差的问题，求差问题，也可以转换成区间和的问题。
 与题目 53.最大子序和 类似
 */
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 1) { return 0; }
    
    int max = 0, profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        int temp = profit + prices[i] - prices[i - 1];
        profit = temp > 0 ? temp : 0;
        max = max < profit ? profit : max;
        printf("[%d]=%d [%d]=%d  temp=%d  profit=%d  max=%d\n", i-1, prices[i-1], i, prices[i], temp, profit, max);
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    int coins[] = {7,1,5,3,6,4};
    int a = maxProfit(coins, 6);
    printf("=== %d\n", a);
    
    /**
     7  1  5  3  6  4
     0  0  4  2  5  3
     
     [0]=7 [1]=1  temp=-6  profit=0  max=0
     [1]=1 [2]=5  temp=4  profit=4  max=4
     [2]=5 [3]=3  temp=2  profit=2  max=4
     [3]=3 [4]=6  temp=5  profit=5  max=5  相当于 6-1=5
     [4]=6 [5]=4  temp=3  profit=3  max=5
     === 5
     
     */
    
    return 0;
}




