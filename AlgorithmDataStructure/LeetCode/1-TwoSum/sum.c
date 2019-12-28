
#include <stdio.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    int *indexs = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                indexs[0] = i;
                indexs[1] = j;
                *returnSize = 2;
                return indexs;
            }
        }
    }
    *returnSize = 0;
    return indexs;
}


int main() {
    
    int size = 0;
    int array[4] = {2,7,11,15};
    int *result = twoSum(array, 4, 7+15, &size);
    for (int i = 0; i < size; i++) {
        printf("-- %d \n", result[i]);
    }
    
    return 0;
}

