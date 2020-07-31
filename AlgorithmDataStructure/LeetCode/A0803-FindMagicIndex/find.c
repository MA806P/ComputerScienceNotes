

#include <stdio.h>


int findMagicIndex0(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == i) {
            return i;
        }
    }
    return -1;
}

/**
 数组可能有重复的，二分法，左右都得处理
 */

int getAnswer(int* nums, int left, int right) {
    if (left > right) { return -1; }
    
    int mid = (right - left) / 2 + left;
    int leftAnswer = getAnswer(nums, left, mid - 1);
    if (leftAnswer != -1) {
        return leftAnswer;
    } else if (nums[mid] == mid) {
        return mid;
    }
    return getAnswer(nums, mid + 1, right);
}

int findMagicIndex(int* nums, int numsSize) {
    return getAnswer(nums, 0, numsSize - 1);
}


int main(int argc, const char * argv[]) {
    
    int a[] = {-1,1,2,4,4,4,6};
    printf("ans = %d\n", findMagicIndex(a, 6));
    return 0;
}


