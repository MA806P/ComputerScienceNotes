

#include <stdio.h>
#include <stdlib.h>

//深度优先搜索
//遇到是1的点就，遍历上下左右，遍历过的点置为0
//最终岛屿的数量，就是进行深度优先搜索的次数，就是树的根节点数量。画个图就可以理解
void dfs(char** grid, int gridSize, int* gridColSize, int x, int y) {
    if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize[0] || grid[x][y] == '0') {
        return;
    }
    grid[x][y] = '0'; //遍历过了就置0
    int dirX[] = {0,1,0,-1};
    int dirY[] = {1,0,-1,0};
    for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i], nextY = y + dirY[i];
        dfs(grid, gridSize, gridColSize, nextX, nextY);
    }
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL ) { return 0; }
    
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                ans += 1;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    char array[3][3] = {{'0','1','0'},{'1','1','0'},{'0','0','1'}};
    
    char **a = (char **)malloc(sizeof(char *)*3);
    for (int i = 0; i < 3; i++) {
        char *a1 = (char *)malloc(sizeof(char)*3);
        for (int j = 0; j < 3; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[3] = {3,3,3};
    
    printf("%d \n", numIslands(a, 3, b));
    
    return 0;
}








