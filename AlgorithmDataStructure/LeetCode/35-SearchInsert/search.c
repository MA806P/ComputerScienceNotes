
#include <stdlib.h>
#include <stdio.h>

/*
int searchInsert(int* nums, int numsSize, int target){
    if (numsSize <= 0) { return 0; }
    if (nums[0] > target) { return 0; }
    if (nums[numsSize - 1] < target) { return numsSize; }
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] < target) {
            if (nums[i+1] >= target) {
                return i + 1;
            }
        } else {
            return i;
        }
    }
    return 0;
}
*/

int searchInsert(int* nums, int numsSize, int target){
    //二分查找
    int left = 0, right = numsSize - 1, mid = 0;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1};
    printf("-- %d\n", searchInsert(a, 1, 2));
    
    return 0;
}



