
#include <stdio.h>
#include <string.h>

//方法一，0..n 求和，然后一个个减，剩的就是缺失的值
int missingNumber0(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    //long sum = (numsSize + 1)*numsSize/2;
    //for (int i = 0; i < numsSize; i++) { sum -= nums[i]; }
    
    //边加边减，防止溢出
    int sum = 0;
    for (int i = 1; i <= numsSize; i++) {
        sum += i;
        sum -= nums[i - 1];
    }
    return sum;
}

//方法二
/**
 异或运算 0^0=0    0^1=1   1^1=0, 任何数和本身异或则为 0
 0 1 2
 0 1 3
 循环异或
 3^(0^0)^(1^1)^(2^3) == 3^3 ^ 0^0 ^ 1^1 ^ 2 = 0^0^0^2 = 0^2 = 2
 */
int missingNumber(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return 0; }
    
    int ans = numsSize;
    for (int i = 0; i < numsSize; i++) {
        ans ^= i ^ nums[i];
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int numsSize = 20;
    int nums[numsSize];
    memset(nums, 0, sizeof(nums));
    for (int i = 0; i <= numsSize; i++) {
        if (i <= 18) {
            nums[i] = i;
        } else {
            nums[i-1] = i;
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    printf("ans = %d\n", missingNumber(nums, numsSize));
    return 0;
}



