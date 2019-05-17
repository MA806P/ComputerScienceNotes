#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  有 n 个台阶，每次可以跨1个台阶或者2个台阶
 *  计算走这 n 个台阶有多少种走法？
 *
 *  递归可能遇到的问题：
 *  堆栈溢出、重复计算、函数调用耗时多、空间复杂度高
 */


// ----------------------------------------

int climbStairs(int n, int *value) {
    if (value[n] != 0 || n <= 2) {
        return value[n];
    }
    
    value[n] = climbStairs(n-1, value) + climbStairs(n-2, value);
    return value[n];
}

int stepUpCount1(int n) {
    int *value = (int *)malloc(sizeof(int) * (n + 1));
    if (value == NULL) {
        return -1;
    }
    int result = 0;
    
    memset(value, 0, sizeof(int) * (n + 1));
    value[0] = 0;
    value[1] = 1;
    value[2] = 2;
    result = climbStairs(n, value);
    free(value);
    
    return result;
}


// ----------------------------------------

int setpUpCount2(int n) {
    
    if (n <= 0) { return -1; }
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    
    return setpUpCount2(n - 1) + setpUpCount2(n -2);
}


// ----------------------------------------

int setpUpCount3(int n) {
    
    if (n <= 0) { return -1; }
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    
    int i, one = 1, two = 2, sum = 0;
    
    for (i = 3; i <= n; i++) {
        sum = one + two;
        one = two;
        two = sum;
    }
    return sum;
}


// ----------------------------------------


int main() {
    
    int i;
    for (i = 0; i <= 6; i++) {
        printf("%d = %d \n", i, stepUpCount1(i));
    }
    
    printf("\n**********\n");
    
    for (i = 0; i <= 6; i++) {
        printf("%d = %d \n", i, setpUpCount2(i));
    }
    
    printf("\n**********\n");
    
    for (i = 0; i <= 6; i++) {
        printf("%d = %d \n", i, setpUpCount3(i));
    }
    
    
    return 0;
}
