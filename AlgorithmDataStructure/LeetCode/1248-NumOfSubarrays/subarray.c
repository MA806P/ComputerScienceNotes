

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 ans = 16 , [1,2,2,1] 前面四个2 后面四个2，4*4=16
 
 [-1,3,6,10,0,0,0,0,0,0,0,0]
 (3-(-1))*(10-6) = 16
 */
int numberOfSubarrays(int* nums, int numsSize, int k){
    if (nums == NULL || k <= 0 || numsSize < k) { return 0; }
    
    int *odd = (int *)malloc(sizeof(int) * (numsSize + 2));
    memset(odd, 0, sizeof(int) * (numsSize + 2));
    
    int ans = 0, count = 0;
    
    //记录奇数的下标
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & 1) { odd[++count] = i; }
    }
    //注意边界的处理
    odd[0] = -1; odd[++count] = numsSize;
    
    for (int i = 1; i + k <= count; i++) {
        ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {2,2,2,1,2,2,1,2,2,2};
    printf("%d \n", numberOfSubarrays(a, 10, 2));
    
    return 0;
}








