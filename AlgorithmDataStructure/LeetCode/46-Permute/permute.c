
#include <stdio.h>
#include <stdlib.h>


/*
 回溯法
 没有重复数字的序列，从 0 开始遍历，
 后面的分别与第一位交换，然后后面的再与第二位交换，依次下去得解。
 
 */

void swapItem(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void backtrack(int* nums, int numsSize, int* returnSize, int** returnArray, int first) {
    if (first == numsSize) {
        returnArray[*returnSize] = nums;
        *returnSize += 1;
    }
    
    for (int i = first; i < numsSize; i++) {
        
        int *items = (int *)malloc(sizeof(int)*numsSize);
        memcpy(items, nums, sizeof(int)*numsSize);
        
        swapItem(items + first, items + i);
        backtrack(items, numsSize, returnSize, returnArray, first + 1);
        swapItem(items + first, items + i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || numsSize <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    *returnSize = 0;
    int **res = (int **)malloc(sizeof(int *) * 100);
    backtrack(nums, numsSize, returnSize, res, 0);
    
    *returnColumnSizes = (int *)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3};
    int returnSize = 0;
    int *returnColumnSizes;
    
    int **res = permute(a, 3, &returnSize, &returnColumnSizes);
    printf("---- %d\n", returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        int size = returnColumnSizes[i];
        int *column = res[i];
        for (int j = 0; j < size; j++) {
            printf(" %d", column[j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}












