
#include <stdlib.h>
#include <stdio.h>

//快速排序
void swap_array(int *a, int *b) {
    int tmp = *a;
    *a = *b; *b = tmp;
}
int partition(int *arr, int p, int r) {
    int i, j;
    i = j = p;
    for(; j < r; j++) {
        if (arr[j] < arr[r]) {
            if (i != j) { swap_array(arr + i, arr + j); }
            i++;
        }
    }
    swap_array(arr + i, arr + r);
    return i;
}
void quick_sort(int *arr, int p, int r) {
    int q;
    if (p >= r) { return; }
    q = partition(arr, p, r);
    quick_sort(arr, p, q - 1);
    quick_sort(arr, q + 1, r);
}


/**
 先进行排序方便操作。
 然后在排序后的数组中，找一个数，然后用两个指针在左右两边移动，找到目标。
 
 怎么移动？
 初始位置，最左端最小的，最右端最大的
 然后三数相加，
 小于0，最左端向右一格变大。
 大于0，最右端向左一格变小。
 
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    
    //排序
    quick_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n --------- \n");
    
    //排序之后，最左大于0，或者最右小于0，不可能找到目标排除
    if (nums[0] > 0 || nums[numsSize - 1] < 0) { return NULL; }
    
    int **returnArray = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    
    for (int i = 0; i < numsSize - 2; ) {
        if (nums[i] > 0) { break; } //左 中 右，左>0 排除
        int second = i + 1, last = numsSize - 1;
        
        do {
            //if (second >= last || (nums[i] * nums[last] > 0)) { break; } //三数符号相同，退出
            //printf("-- %d %d %d \n", nums[i], nums[second], nums[last]);
            
            int result = nums[i] + nums[second] + nums[last];
            if (result == 0) {
                //returnArray = (int **)realloc(returnArray, ((*returnSize) + 1) * sizeof(int *));
                returnArray[*returnSize] = malloc(sizeof(int) * 3);
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[second];
                returnArray[*returnSize][2] = nums[last];
                (*returnSize) += 1;
            }
            
            if (result <= 0) {
                while (second < last) {
                    if (nums[second] == nums[second + 1]) {
                        second++;
                    } else {
                        second++; break;
                    }
                }
            } else {
                while (second < last) {
                    if (nums[last] == nums[last - 1]) {
                        last--;
                    } else {
                        last--; break;
                    }
                }
            }
        } while (second < last);
        while (i < numsSize - 2) {
            if (nums[i] == nums[i + 1]) {
                i++;
            } else {
                i++; break;
            }
        }
    }
    
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }
    
    
    return returnArray;
}


int main(int argc, const char * argv[]) {
    
    int nums[] = {0,0,0};
    int returnSize = 0;
    int *returnColumnSizes;

    int **threes = threeSum(nums, 3, &returnSize, &returnColumnSizes);
    
    printf("------ %d\n", returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("\ni = %d\n", i);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d = %d  ", j, threes[i][j]);
        }
    }
    
    return 0;
}



