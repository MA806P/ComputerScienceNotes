
#include <stdio.h>

//峰谷法
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 0) { return 0; }
    int i = 0, valley = prices[0], peak = prices[0], maxprofit = 0;
    while (i < pricesSize - 1) {
        //找到谷底
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) { i++; }
        valley = prices[i];
        //找到峰顶
        while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) { i++; }
        peak = prices[i];
        //累加，峰谷落差
        maxprofit += peak - valley;
    }
    return maxprofit;
}

//这种方法，其实跟上面峰谷法一样。
//上坡累计差值。
int maxProfit1(int* prices, int pricesSize){
    if (prices == NULL || pricesSize <= 0) { return 0; }
    int maxprofit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i] < prices[i+1]) {
            maxprofit += prices[i+1] - prices[i];
        }
    }
    return maxprofit;
}



int main(int argc, const char * argv[]) {
    int p[] = {7,1,5,3,6,4};
    printf("ans = %d\n", maxProfit(p,6));
    return 0;
}



