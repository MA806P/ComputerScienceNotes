

#include <stdio.h>
#include <stdlib.h>


int numRookCaptures(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize < 1 || boardColSize == NULL) { return 0; }
    
    int ans = -1, pi = 0, pj = 0;
    for (int i = 0; i < boardSize; i++) {
        int colSize = boardColSize[i];
        for (int j = 0; j < colSize; j++) {
            if (board[i][j] == 'R') {
                pi = i; pj = j; ans = 0;
                break;
            }
        }
        if (ans == 0) { break; }
    }
    
    if (ans == -1) { return 0; }
    
    for (int i = pi - 1; i >= 0; i--) {
        if (board[i][pj] == 'B') {
            break;
        } else if (board[i][pj] == 'p') {
            ans += 1; break;
        }
    }
    
    for (int i = pi + 1; i < boardSize; i++) {
        if (board[i][pj] == 'B') {
            break;
        } else if (board[i][pj] == 'p') {
            ans += 1; break;
        }
    }
    
    for (int j = pj - 1; j >= 0; j--) {
        if (board[pi][j] == 'B') {
            break;
        } else if (board[pi][j] == 'p') {
            ans += 1; break;
        }
    }
    
    for (int j = pj + 1; j < boardSize; j++) {
        if (board[pi][j] == 'B') {
            break;
        } else if (board[pi][j] == 'p') {
            ans += 1; break;
        }
    }
    
    
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
   char **board = (char **)malloc(sizeof(char *) * 8);
    board[0] = "........";
    board[1] = "...p....";
    board[2] = "...p....";
    board[3] = "pp.R.pB.";
    board[4] = "........";
    board[5] = "...B....";
    board[6] = "...p....";
    board[7] = "........";
    
    int boardSize = 8;
    int boardColSize[8] = {8,8,8,8,8,8,8,8};
    
    int a = numRookCaptures(board, boardSize, boardColSize);
    printf("ans = %d\n", a);
    
    return 0;
}





