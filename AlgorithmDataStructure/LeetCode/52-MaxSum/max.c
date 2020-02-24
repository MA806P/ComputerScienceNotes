
#include <stdio.h>

int maxSubArray(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) { return 0; }
    
    int max = nums[0], sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        max = max > sum ? max : sum;
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("-- %d\n", maxSubArray(a, 9));
    return 0;
}
