
#include <stdio.h>
#include <stdlib.h>
#import <string.h>


//跟之前螺旋输入题目相似，直接套用，坐标计算方法
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
    
    int **ans = (int **)malloc(sizeof(int **) * n);
    for (int i = 0; i < n; i++) {
        int *row = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) { row[j] = 0; }
        ans[i] = row;
    }
    
    //用来记录是否被访问过
    int **visited = (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n; i++) {
        int *colVisited = (int *)malloc(sizeof(int) * n);
        memset(colVisited, 0, sizeof(int) * n);
        visited[i] = colVisited;
    }
    
    //控制 x y 的遍历方向
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;
    for (int i = 0; i < n * n; i++) {
        visited[x][y] = 1;
        ans[x][y] = i + 1;
        int cx = x + dx[di], cy = y + dy[di];
        if (cx >= 0 && cx < n && cy >= 0 && cy < n && visited[cx][cy] == 0) {
            x = cx; y = cy;
        } else {
            di = (di + 1) % 4; x += dx[di];  y += dy[di];
        }
    }
    
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int returnSize = 0;
    int *columnSize;
    int **ans = generateMatrix(5, &returnSize, &columnSize);
    
    for (int i = 0; i < returnSize; i++) {
        int column = columnSize[i];
        for (int j = 0; j < column; j++) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}





