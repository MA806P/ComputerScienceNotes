
#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    //转置矩阵
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }
    
    //翻转每一行
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize/2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize - j - 1] = tmp;
        }
    }
}


int main(int argc, const char * argv[]) {
    /*
    1 2 3
    4 5 6
    7 8 9
    
    转置矩阵
    1 4 7
    2 5 8
    3 6 9
    
    然后再翻转每一行
    7 4 1
    8 5 2
    9 6 3
    */
    
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
    rotate(a, 3, col);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}





