
#include <stdio.h>

//若数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//时间复杂度必须是 O(log n) 级别。提示使用二分查找
//数组被旋转

/*
//方法1，先找到旋转点，然后判断在旋转点的左右，然后二分查找
//找到旋转点
int findRotateIndex(int *nums, int numsSize) {
    if (nums[0] < nums[numsSize - 1]) { return 0; }
    
    int low = 0, high = numsSize - 1, pivot;
    while (low <= high) {
        pivot = low + (high - low)/2;
        if (nums[pivot] > nums[pivot + 1]) {
            return pivot + 1;
        } else {
            if (nums[0] > nums[pivot]) {
                high = pivot - 1;
            } else {
                low = pivot + 1;
            }
        }
    }
    return 0;
}
 
int search(int* nums, int numsSize, int target){
    if (numsSize <= 0) { return -1; }
    if (numsSize == 1) { return nums[0] == target ? 0 : -1; }
    
    //旋转点
    int rotateIndex = findRotateIndex(nums, numsSize);
    if (nums[rotateIndex] == target) { return rotateIndex; }
    
    int low, high, mid;
    if (rotateIndex == 0) {
        //旋转点0，有序数组
        low = 0;
        high = numsSize - 1;
    } else {
        if (target < nums[0]) {
            //目标值在旋转点的右侧
            low = rotateIndex;
            high = numsSize - 1;
        } else {
            //目标值在旋转点的左侧
            low = 0;
            high = rotateIndex - 1;
        }
    }
    
    while (low <= high) {
        mid = low + (high - low)/2;
        printf("%d %d %d ", low, high, mid);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        
        printf("-- %d %d %d\n", low, high, mid);
    }
    
    return -1;
}
*/


//方法2
int search(int* nums, int numsSize, int target){
    if (numsSize <= 0) { return -1; }
    if (numsSize == 1) { return nums[0] == target ? 0 : -1; }
    
    int low = 0, high = numsSize - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low)/2;
        printf("%d %d %d ", low, high, mid);
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[0] <= nums[mid]) {
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
        printf("-- %d %d %d\n", low, high, mid);
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int nums[] = {5,1,3};
//    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    int a = search(nums, 3, 2);
    printf("=== %d\n", a);
    return 0;
}





