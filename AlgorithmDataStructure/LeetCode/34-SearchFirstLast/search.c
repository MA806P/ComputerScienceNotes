
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *nums, int numsSize, int target, int flag) {
    if (numsSize <= 0) { return -1; }
    if (numsSize == 1) { return nums[0] == target ? 0 : -1; }
    
    int low = 0, high = numsSize - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] == target) {
            if (flag == 1) {
                //查找第一
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                //查找最后一个
                if (mid == numsSize - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
            
        }
    }
    
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    *returnSize = 2;
    int *returnArray = (int *)malloc(sizeof(int) * 2);
    int left = -1, right = -1;
    left = binarySearch(nums, numsSize, target, 1);
    right = binarySearch(nums, numsSize, target, 2);
    returnArray[0] = left;
    returnArray[1] = right;
    
    return returnArray;
}

int main(int argc, const char * argv[]) {
    
    int nums[] = {1,1,2};
    int returnSize = 0;
//    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    int *a = searchRange(nums, 3, 1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("= %d ", a[i]);
    }
    return 0;
}

