
#include <stdio.h>
#include <string.h>


//计数质数
//方法一、一个个的判断，统计。超时
int isPrimes(int n) {
    for (int i = 2; i < n; i++) {
        if (n%i == 0) { return 0; }
    }
    return 1;
}
int countPrimes0(int n){
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrimes(i)) { count++; }
    }
    return count;
}


//方法二、优化
/**
 1、比2大的偶数肯定不是质数，排除。
 2、质数的倍数一定不是质数，排除。
 所以把【比2大的偶数】和【质数的奇数倍数】排除掉，剩下的就是质数。
 */
int countPrimes(int n){
    if (n <= 2) { return 0; }
    
    int flag[n];
    memset(flag, 0, sizeof(flag));
    int count = 1; //n=3 时，就一个质数 2
    
    //从 3 开始，只遍历奇数
    for (int i = 3; i < n; i+=2) {
        if (flag[i] == 0) { //i 为质数的情况
            for (int j = 3; i * j < n; j+=2) {
                flag[i*j] = 1; //质数的奇数倍数，标记为非质数
            }
            count++;
        }
    }
    
    return count;
}


int main(int argc, const char * argv[]) {
    printf("ans = %d \n", countPrimes(7));
    return 0;
}



