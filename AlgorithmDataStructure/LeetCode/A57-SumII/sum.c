#include <stdio.h>
#include <stdlib.h>

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (target/2));
    (*returnColumnSizes)[0] = 0;
    int **result = (int **)malloc(sizeof(int *) * 10);
    
    for (int l = 1, r = 2; l < r; ) {
        int sum = (l + r) * (r - l + 1) / 2;
        if (sum == target) {
            int count = r - l + 1;
            int *columns = (int *)malloc(sizeof(int) * count);
            for (int n = 0; n < count; n++) {
                columns[n] = l + n;
            }
            result[*returnSize] = columns;
            (*returnColumnSizes)[*returnSize] = count;
            (*returnSize) += 1;
            l++;
        } else if (sum < target) {
            r++;
        } else {
            l++;
        }
    }
    return result;
}



int main(int argc, const char * argv[]) {
    
    int returnSize = 0;
    int *returnColumnSizes;
    int **res = findContinuousSequence(15, &returnSize, &returnColumnSizes);
    
    printf("return ==== %d \n", returnSize);
    for (int n = 0; n < returnSize; n++) {
        int *column = res[n];
        int columnSize = returnColumnSizes[n];
        printf("size = %d == ", columnSize);
        for (int i = 0; i < columnSize; i++) {
            printf("%d ", column[i]);
        }
        printf("\n");
    }
    return 0;
}

