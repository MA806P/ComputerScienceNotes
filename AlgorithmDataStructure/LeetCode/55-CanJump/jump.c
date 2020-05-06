

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 贪心算法
 依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置
 用 x + nums[x] 更新最远可以到达的位置。
 */

bool canJump(int* nums, int numsSize){
    
    int rightMost = 0;
    for (int i = 0; i < numsSize; i++) {
        printf("----- %d = %d %d < %d\n", i, nums[i], rightMost, i + nums[i]);
        if (i <= rightMost) {
            rightMost = rightMost > i + nums[i] ? rightMost : i + nums[i];
            if (rightMost >= numsSize - 1) { return true; }
        }
        printf("****** %d = %d %d < %d\n", i, nums[i], rightMost, i + nums[i]);
    }
    return false;
    
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,2,9,0,0,0};
    printf("ans = %d\n", canJump(a, 7));
    
    /**
     ----- 0 = 1 0 < 1
     ****** 0 = 1 1 < 1
     ----- 1 = 3 1 < 4
     ****** 1 = 3 4 < 4
     ----- 2 = 2 4 < 4
     ****** 2 = 2 4 < 4
     ----- 3 = 9 4 < 12
     ans = 1
     */
    
    /**
     [0] true
     [1,0] true
     [0,1] false
     [1,2,3] true
     [1,3,2,9,0,0,0];
     */
    
    return 0;
}




