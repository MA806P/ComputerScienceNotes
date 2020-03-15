
#include <stdio.h>
#include <stdlib.h>

//深度优先搜索
//遇到是1的点就，遍历上下左右，计算过的点置为0
int dfs(int** grid, int gridSize, int* gridColSize, int x, int y) {
    if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize[0] || grid[x][y] == 0) {
        return 0;
    }
    grid[x][y] = 0; //计算过了就置0
    int dirX[] = {0,1,0,-1};
    int dirY[] = {1,0,-1,0};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i], nextY = y + dirY[i];
        ans += dfs(grid, gridSize, gridColSize, nextX, nextY);
    }
    return ans;
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL ) { return 0; }
    
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                int temp = dfs(grid, gridSize, gridColSize, i, j);
                ans = ans < temp ? temp : ans;
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int array[3][3] = {{0,1,0},{1,1,0},{0,0,1}};
    
    int **a = (int **)malloc(sizeof(int *)*3);
    for (int i = 0; i < 3; i++) {
        int *a1 = (int *)malloc(sizeof(int)*3);
        for (int j = 0; j < 3; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[3] = {3};
    
    printf("%d \n", maxAreaOfIsland(a, 3, b));
    
    return 0;
}




