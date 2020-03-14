
#include <stdio.h>
#include <stdlib.h>


//方法一，不停地重复计算，需要改进
int climbStairs0(int n){
    if (n <= 0) { return  0; }
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    
    return climbStairs0(n - 1) + climbStairs0(n - 2);
}


//方法二，保存一下计算值
long climb(int n, long *value) {
    if (value[n] != 0 || n <= 2) {
        return value[n];
    }
    value[n] = climb(n - 1, value) + climb(n - 2, value);
    return value[n];
}

int climbStairs1(int n) {
    if (n <= 0) { return  0; }
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    
    long *value = (long *)malloc(sizeof(long) * (n+1));
    for (int i = 0; i < n+1; i++) {
        value[i] = 0;
    }
    value[1] = 1;
    value[2] = 2;
    long res = climb(n, value);
    free(value);
    
    if (res > 2147483647) { return 0; }
    return (int)res;
}

int climbStairs(int n) {
    if (n <= 0) { return  0; }
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    
    int one = 1, two = 2, sum = 0;
    for (int i = 3; i <= n; i++) {
        sum = one + two;
        one = two;
        two = sum;
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    
    printf("%d\n", climbStairs(45));
    
    return 0;
}




