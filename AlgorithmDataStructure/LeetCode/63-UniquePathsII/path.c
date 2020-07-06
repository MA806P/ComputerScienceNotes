
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 这个和上一题一样的方法，就是判断一下障碍
 注意 (0,0)=1 的情况
 
 n = 3, 三行，每次循环计算没列的值，累加修改数组中的值
 1   1   1   1   1   1   1
 1   2   0   1   2   3   4
 1   3   3   4   6   9   13
 //每一行计算的值 = 使用上一行，和这一行前面一位的和 = f[j] + f[j-1]
 f[j]还是上一行的旧值，即将计算新值，替换掉。f[j-1]在上一次循环中已替换为新值
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    
    int m = obstacleGridSize, n = obstacleGridColSize[0];
    int f[n];
    memset(f, 0, sizeof(f));
    f[0] = obstacleGrid[0][0] == 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                f[j] = 0;
            } else if (j > 0 && obstacleGrid[i][j-1] == 0){
                f[j] = f[j - 1] + f[j];
            }
            printf("%d=%d ",j, f[j]);
        }
        printf("\n");
    }
    return f[n - 1];
}

int main(int argc, const char * argv[]) {
    
    int a[3][7] = {{0,0,0,0,0,0,0},{0,0,1,0,0,0,0},{0,0,0,0,0,0,0}};
    int b[3] = {7,7,7};
    int **obstacleGrid = (int **)malloc(sizeof(int **) * 3);
    for (int i = 0; i < 3; i++) {
        int *temp = (int *)malloc(sizeof(int) * 7);
        for (int j = 0; j < 7; j++) {
            temp[j] = a[i][j];
            printf("%d ", temp[j]);
        }
        obstacleGrid[i] = temp;
        printf("\n");
    }
    printf("\n");
    
    
    int ans = uniquePathsWithObstacles(obstacleGrid, 3, b);
    printf("ans = %d\n", ans);
    
    
    return 0;
}



