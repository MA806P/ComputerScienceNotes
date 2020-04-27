
#include <stdio.h>
#include <stdlib.h>


/*
 回溯法
 没有重复数字的序列，从 0 开始遍历，
 后面的分别与第一位交换，然后后面的再与第二位交换，依次下去得解。
 [1,2,3]
 
 f=0,i=0                 f=0,i=1                f=0,i=2
 [1,2,3]                 [2,1,3]                [3,2,1]
 
 f=1,i=1  f=1,i=2    f=1,i=1   f=1,i=2   f=1,i=1  f=1,i=2
 [1,2,3]  [1,3,2]     [2,1,3]  [2,3,1]   [3,2,1]  [3,1,2]
 
 f=2,i=2   f=2,i=2     f=2,i=2  f=2,i=2   f=2,i=2  f=2,i=2
 [1,2,3]   [1,3,2]     [2,1,3]  [2,3,1]   [3,2,1]  [3,1,2]
        
 
 */

void swapItem(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void backtrack(int* nums, int numsSize, int* returnSize, int** returnArray, int first) {
    if (first == numsSize) {
        returnArray[*returnSize] = nums;
        *returnSize += 1;
        return;
    }
    
    for (int i = first; i < numsSize; i++) {
        
        int *items = (int *)malloc(sizeof(int)*numsSize);
        memcpy(items, nums, sizeof(int)*numsSize);
        
        swapItem(items + first, items + i);
        backtrack(items, numsSize, returnSize, returnArray, first + 1);
        swapItem(items + first, items + i);
        //上面的作用，这个分支结束后，在交换回来，在原来的基础上再交换，而不是在交换后的基础上交换
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












