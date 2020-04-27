
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target){
    if (numsSize <= 0) { return false; }
    if (numsSize == 1) { return nums[0] == target ? true : false; }
    
    int low = 0, high = numsSize - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low)/2;
        printf("1 - %d %d %d \n", low, high, mid);
        if (nums[mid] == target) {  return true; }
        
        //可能有重复的，这里判断不出来哪部分有序，直接 low+1
        //  [1,3,1,1,1]       [1,1,1,3,1]
        if (nums[low] == nums[mid]) { low++; continue; }
        
        if (nums[0] < nums[mid]) {
            //前半部分有序
            if (nums[0] <= target && target < nums[mid]) {
                //目标值在前半部分，有序的数组中。
                high = mid - 1;
            } else {
                //目标值在后半部，后半部分是旋转的数组。
                low = mid + 1;
            }
        } else {
            //后半部分有序
            if (nums[mid] < target && target <= nums[numsSize - 1]) {
                //目标值在后半部分，有序
                low = mid + 1;
            } else {
                //目标值在前半部分，前半部分旋转的数组
                high = mid - 1;
            }
        }
        printf("2 -- %d %d %d\n", low, high, mid);
    }
    return false;
}





int main(int argc, const char * argv[]) {
    
    int nums[] = {1,1,1,3,1};
//    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    bool a = search(nums, 5, 3);
    printf("=== %d\n", a);
    return 0;
}




















