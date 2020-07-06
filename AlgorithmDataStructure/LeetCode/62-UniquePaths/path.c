
#include <stdio.h>
#include <stdlib.h>


/**
 1
 1   1
 1   2   1
 1   3   3   1
 1   4   6   4   1
 */

/**
 1   1   1   1   1   1   1
 1   2   3   4   5   6   7
 1   3   6  10  15 21  28
 
 */
int uniquePaths(int m, int n){
    int *ans = (int *)malloc(sizeof(int *) * n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[j] = (i > 0 && j > 0) ? ans[j-1] + ans[j] : 1;
        }
    }
    /**
     m = 3, n = 7, 三行，每次循环计算每行的值，累加修改数组中的值
     i = 0   [1,1,1,1,1,1,1]
     i = 1   [1,2,3,4,5,6,7]
     i = 2   [1,3,6,10,15,21,28]
     //每一行计算的值 = 使用上一行，和这一行前面一位的和 = ans[j] + ans[j-1]
     a[j]还是上一行的旧值，即将计算新值，替换掉。a[j-1]在上一次循环中已替换为新值
     */
    
    int res = ans[n-1];
    free(ans);
    return res;
}


int main(int argc, const char * argv[]) {
    
    printf("ans = %d\n", uniquePaths(6,4));
    return 0;
}



