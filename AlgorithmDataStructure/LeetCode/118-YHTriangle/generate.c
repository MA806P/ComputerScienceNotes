
#include <stdio.h>
#include <stdlib.h>


/**
 
 1
 1   1
 1   2   1
 1   3   3   1
 1   4   6   4   1
 */



int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    *returnSize = numRows;
    int **ans = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    if (numRows <= 0) { return ans; }
    
    
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        int *rows = (int *)malloc(sizeof(int) * (i + 1));
        rows[0] = 1;
        for (int j = 1; j < i; j++) {
            rows[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        rows[i] = 1;
        ans[i] = rows;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int returnSize = 0;
    int *returnColumnSizes;
    
    int **ans = generate(6, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        int levelSize = returnColumnSizes[i];
        for (int j = 0; j < levelSize; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}



