

#include <stdio.h>

//方法一、另开一个数组，遍历统计0的个数，
//把不是0的暂存另外数组中，再转移到原数组末尾补0。

//方法二、分两步，先把非0的数移到前面去，顺便统计0的个数。然后根据0的个数后面的置0
void moveZeroes0(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return; }
    
    int cnt = 0;
    //把非0的数移到前面去
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) { nums[cnt++] = nums[i]; }
    }
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf(" cnt = %d \n", cnt);
    
    //后面的置0
    for (int  i = cnt; i < numsSize; i++) {
        nums[i] = 0;
    }
}

//方法三、双指针。遍历一遍，前面遇到非0 就跟后面指向0的交换一下
//0,1,2,0,3,4  ->  1,2,0,0,3,4 -> 1,2,3,0,0,4 -> 1,2,3,4,0,0
void moveZeroes(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return; }
    
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (i > j) {
                int temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
            }
            j++;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int numsSize = 6;
    int nums[] = {0,1,2,0,3,4};
    moveZeroes(nums, numsSize);
    
    //printf("0 1 2 0 3 4\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}


