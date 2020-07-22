
#include <stdio.h>

int findMin(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1 || nums[0] < nums[numsSize - 1]) { return nums[0]; }
    
    int low = 0, high = numsSize - 1, mid = 0;
    
    while (low < high) {
        mid = low + (high - low)/2;
        printf("1 - [%d]=%d [%d]=%d  [%d]=%d \n", low, nums[low], mid,nums[mid], high, nums[high]);
        
        if (nums[mid] < nums[high]) {
            //最小值在前半部分，后半部分有序
            high = mid;
        } else if (nums[mid] > nums[high]){
            //最小值在后半部分，前半部分有序
            low = mid + 1;
        } else {
            //有重复的，这里判断不出来哪部分有序，直接 low+1
            //  [1,3,1,1,1] [1,1,1,3,1]  [1,1,1,0,1]
            high--;
        }
        printf("2 - [%d]=%d [%d]=%d  [%d]=%d \n", low, nums[low], mid,nums[mid], high, nums[high]);
    }
    return nums[low];
}

int main(int argc, const char * argv[]) {
    
//    int nums[] = {3,1};
    int nums[] = {1,1,1,0,1};
    //int nums[] = {0,1,2,3,4,5,6,7,8,9};
    //2,3,4,5,6,7,8,9,0,1
    printf("ans = %d\n", findMin(nums, 2));
    return 0;
}



