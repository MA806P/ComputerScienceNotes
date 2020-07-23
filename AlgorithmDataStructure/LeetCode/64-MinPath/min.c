
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minPathSum(int** grid, int gridSize, int* gridColSize){
    
    if (grid == NULL || grid <= 0 || gridColSize == NULL || gridColSize[0] <= 0) {
        return 0;
    }
    int m = gridSize, n = gridColSize[0];
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { printf("%d ", dp[i][j]); }
        printf("\n");
    }
    printf("\n");
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int temp = dp[i-1][j] > dp[i][j-1] ? dp[i][j-1] : dp[i-1][j];
            dp[i][j] = grid[i][j] + temp;
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { printf("%d ", dp[i][j]); }
        printf("\n");
    }
    printf("\n");
    
    return dp[m-1][n-1];
}


int main(int argc, const char * argv[]) {

    int row = 2;
    int a[][3] = {{1,2,3},{4,5,6}};
    int b[] = {3,3};
    int **grid = (int **)malloc(sizeof(int **) * row);
    for (int i = 0; i < row; i++) {
        int n = b[i];
        int *temp = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            temp[j] = a[i][j];
            printf("%d ", a[i][j]);
        }
        grid[i] = temp;
        printf("\n");
    }
    printf("\n");
    
    printf("ans = %d\n", minPathSum(grid, row, b));
    return 0;
}



