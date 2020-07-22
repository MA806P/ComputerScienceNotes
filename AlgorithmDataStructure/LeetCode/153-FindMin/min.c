
#include <stdio.h>

int findMin(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1 || nums[0] < nums[numsSize - 1]) { return nums[0]; }
    
    int low = 0, high = numsSize - 1, mid = 0;
    
    while (low <= high) {
        mid = low + (high - low)/2;
        printf("1 - [%d]=%d [%d]=%d  [%d]=%d \n", low, nums[low], mid,nums[mid], high, nums[high]);
        
        //数组没有重复的
        //mid恰好是最小值情况  12345  45[1]23  3[4]12   2,3,4,5,6,7,8,9,0,1
        if (nums[mid] > nums[mid + 1]) { return nums[mid + 1]; }
        if (nums[mid] < nums[mid - 1]) { return nums[mid]; }
        
        if (nums[mid] > nums[0]) {
            //最小值在后半部分，前半部分有序
            low = mid + 1;
        } else {
            //最小值在前半部分，后半部分有序
            high = mid - 1;
        }
        printf("2 - [%d]=%d [%d]=%d  [%d]=%d \n", low, nums[low], mid,nums[mid], high, nums[high]);
    }
    return -1;
}

int main(int argc, const char * argv[]) {

    int nums[] = {3,4,5,6,7,8,9,0,1,2};
    
    printf("ans = %d\n", findMin(nums, 10));
    return 0;
}



