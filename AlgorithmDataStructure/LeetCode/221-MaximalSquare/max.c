

#include <stdio.h>
#include <stdlib.h>


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL || matrixSize <= 0 || matrixColSize == NULL) { return 0; }
    int colSize = matrixColSize[0];
    if (colSize <= 0) { return 0; }
    
    int maxSide = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == '1') {
                //遇到 1 作为正方形左上角
                maxSide = maxSide > 1 ? maxSide : 1;
                //计算可能最大的正方形
                int currentMaxSize = matrixSize - i > colSize - j ? colSize - j : matrixSize - i;
                for (int k = 1; k < currentMaxSize; k++) {
                    int flag = 1;
                    if (matrix[i+k][j+k] == '0') { break; }
                    
                    for (int m = 0; m < k; m++) {
                        if (matrix[i+k][j+m] == '0' || matrix[i+m][j+k] == '0') {
                            flag = 0; break;
                        }
                    }
                    
                    if (flag == 1) {
                        maxSide = maxSide > k + 1 ? maxSide : k + 1;
                    } else {
                        break;
                    }
                    
                }
            }
        }
    }
    
    return maxSide * maxSide;
}

int main(int argc, const char * argv[]) {
    
    char **board = (char **)malloc(sizeof(char *) * 4);
    board[0] = "10100";
    board[1] = "10111";
    board[2] = "11111";
    board[3] = "10010";
    
    int colSize[] = {5,5,5,5};
    
    printf("ans = %d\n", maximalSquare(board, 4, colSize));
    return 0;
}


