

#include <stdio.h>
#include <stdlib.h>

int surfaceArea0(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL) { return 0; }
    
    int dirX[4] = {-1, 0, 1, 0}; //方向上下左右
    int dirY[4] = {0, -1, 0, 1};
    int ans = 0; //结果
    
    for (int i = 0; i < gridSize; i++) {
        int colSize = gridColSize[i];
        for (int j = 0; j < colSize; j++) {
            if (grid[i][j] > 0) {
                ans += 2;
                for (int n = 0; n < 4; n++) {
                    int ti = i + dirX[n], tj = j + dirY[n], tv = 0;
                    if (ti >= 0 && ti < gridSize && tj >= 0 && tj < colSize) {
                        tv = grid[ti][tj];
                    }
                    int temp = grid[i][j] - tv;
                    ans += temp > 0 ? temp : 0;
                }
            }
        }
    }
    
    return ans;
    
}


int surfaceArea(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL) { return 0; }
    int ans = 0; //结果
    
    for (int i = 0; i < gridSize; i++) {
        int colSize = gridColSize[i];
        printf("colsize = %d\n", colSize);
        for (int j = 0; j < colSize; j++) {
            int level = grid[i][j];
            if (level > 0) {
                ans += level * 4 + 2;
                //前面，上面有遮挡的减去
                if (i > 0) { ans -= ((level > grid[i-1][j] ? grid[i-1][j] : level) * 2); }
                if (j > 0) { ans -= ((level > grid[i][j-1] ? grid[i][j-1] : level) * 2); }
            }
            printf("%d %d\n", level, ans);
        }
    }
    
    return ans;
    
}



int main(int argc, const char * argv[]) {
    
    int array[3][3] = {{1,1,1},{1,0,1},{1,1,1}};
    
    int **a = (int **)malloc(sizeof(int *)*3);
    for (int i = 0; i < 3; i++) {
        int *a1 = (int *)malloc(sizeof(int)*3);
        for (int j = 0; j < 3; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[3] = {3,3,3};
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("ans = %d\n", surfaceArea0(a, 3, b));
    
    return 0;
}





