

#include <stdio.h>
#include <stdlib.h>



int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    
     int column = matrixColSize[0];
    *returnSize = matrixSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        (*returnColumnSizes)[i] = column;
    }
    
    
    if (matrix == NULL || matrixSize < 1 || matrixColSize == NULL) {
        return matrix;
    }
    
    
    for (int i = 0; i < matrixSize; i++) {
        int column = matrixColSize[i];
        for (int j = 0; j < column; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
   
    int **ans = (int **)malloc(sizeof(int **) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        int *row = (int *)malloc(sizeof(int) * column);
        for (int j = 0; j < column; j++) {
            row[j] = 40000;
        }
        ans[i] = row;
    }
    
    
    //为 0 的位置，值为 0
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] == 0) {
                ans[i][j] = 0;
            }
        }
    }
    
    
    
    //只有水平向左、垂直向上移动
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < column; j++) {
            if (i - 1 >= 0) {
                ans[i][j] = ans[i][j] < ans[i - 1][j] + 1 ? ans[i][j] : (ans[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                ans[i][j] = ans[i][j] < ans[i][j - 1] + 1 ? ans[i][j] : (ans[i][j - 1] + 1);
            }
        }
    }
    
    //只有水平向左、垂直向下移动
    for (int i = matrixSize - 1; i >= 0; i--) {
        for (int j = 0; j < column; j++) {
            if (i + 1 < matrixSize) {
                ans[i][j] = ans[i][j] < ans[i + 1][j] + 1 ? ans[i][j] : (ans[i + 1][j] + 1);
            }
            if (j - 1 >= 0) {
                ans[i][j] = ans[i][j] < ans[i][j - 1] + 1  ? ans[i][j] : (ans[i][j - 1] + 1);
            }
        }
    }
    
    //只有水平向右、垂直向上移动
    for (int i = 0; i < matrixSize; i++) {
        for (int j = column - 1; j >= 0; j--) {
            if (i - 1 >= 0) {
                ans[i][j] = ans[i][j] < ans[i - 1][j] + 1 ? ans[i][j] : (ans[i - 1][j] + 1);
            }
            if (j + 1 < column) {
                ans[i][j] = ans[i][j] < ans[i][j + 1] + 1 ? ans[i][j] : (ans[i][j + 1] + 1);
            }
        }
    }
    
    //只有水平向右、垂直向下移动
    for (int i = matrixSize - 1; i >= 0; i--) {
        for (int j = column - 1; j >= 0; j--) {
            if (i + 1 < matrixSize) {
                ans[i][j] = ans[i][j] < ans[i + 1][j] + 1 ? ans[i][j] : (ans[i + 1][j] + 1);
            }
            if (j + 1 < column) {
                ans[i][j] = ans[i][j] < ans[i][j + 1] + 1 ? ans[i][j] : (ans[i][j + 1] + 1);
            }
        }
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int a[3][3] = {{0,0,0},{0,1,0},{1,1,1}};
    int b[3] = {3,3,3};
    int **intervals = (int **)malloc(sizeof(int **) * 3);
    for (int i = 0; i < 3; i++) {
        int *temp = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            temp[j] = a[i][j];
        }
        intervals[i] = temp;
    }
    
    
    
    
    int returnSize = 0;
    int *columnSize;
    int **ans = updateMatrix(intervals, 3, b, &returnSize, &columnSize);
    
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




