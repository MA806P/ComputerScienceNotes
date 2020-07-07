
#include <stdio.h>

int m_max(int a, int b) {
    return a > b ? a : b;
}

/**
 遍历，计算偷与不偷的两种情况，比较大小累加
  不偷 = 上家累计值
  偷 =  上上家累计值+当前家值
  结果 =  max(不偷，偷)
  下一次循环更新值，上家累计值=结果
 
      2   1     1       2
 偷       1    2+1    2+2
 不       2      2      3    4  = sum1
 =        2      3      4        = sum2
 
      2   7   9       3     1
 偷       7  2+9   7+3   11+1
 不       2   7      11     11
 =        7   11     11    12
 */
int rob(int* nums, int numsSize){
    if (nums ==  NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    
    int sum1 = nums[0], sum2 = m_max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        int temp = sum2;
        sum2 = m_max(sum1 + nums[i], sum2);
        sum1 = temp;
    }
    return sum2;
}

int main(int argc, const char * argv[]) {
    
    int nums[] = {2,7,9,3,1};
    int ans = rob(nums, 5);
    printf("ans = %d\n", ans);
    
    return 0;
}



