
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

/**
 上面是三数和的解题思路。
 本题四数和 跟三数之和相似，相比多了一个指针。
 排序后，先固定两个指针 i = 0，j = i + 1 移动后面两个 second = j + 1，last = numsSize - 1
 四个数相加，大于target last--, 小于 target second++
 然后循环 j, i
 */


int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
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
    
    int **returnArray = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    
    for (int i = 0; i < numsSize - 3; ) {
        
        for (int j = i + 1; j < numsSize - 2; ) {
            int second = j + 1, last = numsSize - 1;
            do {
                //printf("-- %d %d %d %d \n", nums[i], nums[j], nums[second], nums[last]);
                int result = nums[i] + nums[j] + nums[second] + nums[last];
                if (result == target) {
                    returnArray[*returnSize] = malloc(sizeof(int) * 4);
                    returnArray[*returnSize][0] = nums[i];
                    returnArray[*returnSize][1] = nums[j];
                    returnArray[*returnSize][2] = nums[second];
                    returnArray[*returnSize][3] = nums[last];
                    (*returnSize) += 1;
                }
                
                if (result <= target) {
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
            
            while (j < numsSize - 2) {
                if (nums[j] == nums[j + 1]) {
                    j++;
                } else {
                    j++; break;
                }
            }
            
        }
        
        while (i < numsSize - 3) {
            if (nums[i] == nums[i + 1]) {
                i++;
            } else {
                i++; break;
            }
        }
    }
    
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 4;
    }
    
    
    return returnArray;
}


int main(int argc, const char * argv[]) {
    
    int nums[] = {1,-2,-5,-4,-3,3,3,5};
    int returnSize = 0;
    int *returnColumnSizes;

    int **fours = fourSum(nums, 8, -11, &returnSize, &returnColumnSizes);
    
    printf("------ %d\n", returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("\ni = %d\n", i);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d = %d  ", j, fours[i][j]);
        }
    }
    
    return 0;
}



