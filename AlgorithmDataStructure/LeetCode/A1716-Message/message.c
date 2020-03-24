

#include <stdio.h>

//这种递归，超出时间限制
int countMssage(int *nums, int numsSize, int from) {
    if (nums == NULL || numsSize - from < 1) { return 0; }
    if (numsSize - from < 2) { return nums[from]; }
    if (numsSize - from < 3) { return nums[from] > nums[from + 1] ? nums[from] : nums[from+1]; }
    
    int temp1 = nums[from] + countMssage(nums, numsSize, from + 2);
    int temp2 = nums[from+1] + countMssage(nums, numsSize, from + 3);
    return temp1 > temp2 ? temp1 : temp2;
}
int massage0(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) { return 0; }
    return countMssage(nums, numsSize, 0);
}



//动态规划
/*
            2     1     4       5        3      1       1        3
 tdp0    0     2     2       6        7      9       9        10
 tdp1    2   0+1   2+4   2+5    6+3   7+1   9+1      9+3
 
 (2)               = 2
 (2,1)            = 0+1 < 2 = 2
 (2,1,4)         = 2(前前一个)+4 > 2 = 6
 (2,1,4,5)      = 2(前前一个)+5 > 6 = 7
 (2,1,4,5,3)   = 6(前前一个)+3 > 7 = 9
 (2,1,4,5,3,1) = 7(前前一个)+1 > 9 = 9
 */
int massage(int* nums, int numsSize){
    if (nums == NULL || numsSize < 1) { return 0; }
    if (numsSize < 2) { return nums[0]; }
    
    int dp0 = 0, dp1 = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int tdp0 = dp0 > dp1 ? dp0 : dp1;
        int tdp1 = dp0 + nums[i];
        dp0 = tdp0;
        dp1 = tdp1;
    }
    return dp0 > dp1 ? dp0 : dp1;
}


int main(int argc, const char * argv[]) {
    
    int a[] = {2,1,4,5,3,1,1,3};
    printf("ans = %d\n", massage(a, 8));
    
    return 0;
}





