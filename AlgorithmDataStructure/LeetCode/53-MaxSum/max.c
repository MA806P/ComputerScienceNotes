
#include <stdio.h>
#include <stdlib.h>


//暴力解法，遍历所有子序组合
int maxSubArray0(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) { return 0; }
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

//动态规划
//dp[i]=max(dp[i-1]+nums[i], nums[i])
int maxSubArray1(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) { return 0; }
    int max = nums[0], sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int temp = sum + nums[i];
        sum = temp > nums[i] ? temp : nums[i];
        max = sum > max ? sum : max;
    }
    return max;
}

//贪心算法
//累加sum，如sum<0放弃前面的重新开始继续依次加下去，比较记录下最大值
//其实跟上面的动态规划差不多，sum + nums[i] > nums[i] => sum>0
int maxSubArray2(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) { return 0; }
    int max = nums[0], sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum = sum > 0 ? sum + nums[i] : nums[i];
        max = sum > max ? sum : max;
    }
    return max;
}





//分治法
int crossSum(int *nums, int left, int right, int mid) {
    if (left == right) { return nums[left]; }
    
    int sum = 0;
    int leftMax = nums[mid];
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        leftMax = sum > leftMax ? sum : leftMax;
    }
    
    sum = 0;
    int rightMax = nums[mid + 1];
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        rightMax = sum > rightMax ? sum : rightMax;
    }
    printf("     cross = %d %d %d = %d\n", left, mid, right, leftMax+rightMax);
    return leftMax + rightMax;
}

int helper(int *nums, int left, int right) {
    if (left == right) { return nums[left]; }
    
    int mid = left + (right - left)/2;
    printf("---%d  %d  %d---\n", left, mid, right);
    int leftMax = helper(nums, left, mid);
    printf("   -- left = %d --\n", leftMax);
    int rightMax = helper(nums, mid + 1, right);
    printf("   -- right = %d --\n", rightMax);
    int corssMax = crossSum(nums, left, right, mid);
    
    int max = leftMax > rightMax ? leftMax : rightMax;
    max = corssMax > max ? corssMax : max;
    
    return max;
}

int maxSubArray(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) { return 0; }
    return helper(nums, 0, numsSize - 1);
}

int main(int argc, const char * argv[]) {
    
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("-- %d\n", maxSubArray(a, 9));
    return 0;
}





