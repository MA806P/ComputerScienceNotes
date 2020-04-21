


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrix == NULL || matrixSize <= 0 || matrixColSize == NULL) {
        int *ans = (int *)malloc(sizeof(int));
        *returnSize = 0;
        return ans;
    }
    
    int colSize = matrixColSize[0];
    *returnSize = matrixSize * colSize;
    int *ans = (int *)malloc(sizeof(int) * (*returnSize));
    
    //用来记录是否被访问过
    int **seen = (int **)malloc(sizeof(int *)*matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        int *colSeen = (int *)malloc(sizeof(int) * colSize);
        memset(colSeen, 0, sizeof(int) * colSize);
        seen[i] = colSeen;
    }
    
    //控制 x y 的遍历方向
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;
    for (int i = 0; i < (*returnSize); i++) {
        ans[i] = matrix[x][y];
        seen[x][y] = 1;
        int cx = x + dx[di], cy = y + dy[di];
        if (cx >= 0 && cx < matrixSize && cy >= 0 && cy < colSize && seen[cx][cy] == 0) {
            x = cx; y = cy;
        } else {
            di = (di + 1) % 4; x += dx[di];  y += dy[di];
        }
    }
    
    return ans;
}





int main(int argc, const char * argv[]) {
    
    int m[3][3] = {1,2,3,4,5,6,7,8,9};
    
    int **a = (int **)malloc(sizeof(int *)*3);
    a[0] = (int *)malloc(sizeof(int) * 3);
    a[1] = (int *)malloc(sizeof(int) * 3);
    a[2] = (int *)malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = m[i][j];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int col[3] = {3,3,3};
    int ansSize = 0;
    int *ans = spiralOrder(a, 3, col, &ansSize);
    
    for (int i = 0; i < ansSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}





