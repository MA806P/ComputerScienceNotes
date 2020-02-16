
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isRepeat(char *chars) {
    int marks[9] = {0};
    for (int i = 0; i < 9; i++) {
        char c = chars[i];
        if (c >= '1' && c <= '9') {
            int cInt = c - '1';
            if (marks[cInt] == 1) {
                return true;
            } else {
                marks[cInt] = 1;
            }
        }
    }
    return false;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if (boardSize <= 0) { return false; }
    
    //行
    for (int i = 0; i < 9; i++) {
        bool repeated = isRepeat(board[i]);
        if (repeated) {
            return false;
        }
    }
    
    //列
    for (int i = 0; i < 9; i++) {
        char *col = (char *)malloc(sizeof(char) * 9);
        for (int j = 0; j < 9; j++) {
            col[j] = board[j][i];
        }
        bool repeated = isRepeat(col);
        if (repeated) {
            return false;
        }
    }
    
    //方
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 3; i++) {
            char *col = (char *)malloc(sizeof(char) * 9);
            for (int j = 0; j < 9; j++) {
                col[j] = board[i*3+j/3][n*3+j%3];
            }
            bool repeated = isRepeat(col);
            if (repeated) {
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d = %d %d \n", j, i*3+j/3, n*3+j%3);
            }
            printf("\n");
        }
        printf("------\n");
    }
    
    
    return 0;
}



