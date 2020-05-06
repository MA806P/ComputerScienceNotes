

#include <stdio.h>

/**
 方法一，反向查找
 先找到哪个位置可以跳到最后，找到了这算一步。
 然后以那个位置为终点，再找哪个位置可以跳到，找到了这又算一步
 这个方法时间复杂度较高 O(n^2)
 
 {1,3,2,9,0,0,0} 7
 -- start --
  nums[0]=1, 1 >= 6
  nums[1]=3, 4 >= 6
  nums[2]=2, 4 >= 6
  nums[3]=9, 12 >= 6
 -- end 3--
 -- start --
  nums[0]=1, 1 >= 3
  nums[1]=3, 4 >= 3
 -- end 1--
 -- start --
  nums[0]=1, 1 >= 1
 -- end 0--
 
 */
int jump0(int* nums, int numsSize){
    
    int position = numsSize - 1, steps = 0;
    int flag = 0; //这个标志，是防止跳不到最后一个位置，无限循环。
    while (position > 0) {
        printf("-- start --\n");
        flag = 0;
        for (int i = 0; i < position; i++) {
            printf(" nums[%d]=%d, %d >= %d\n", i, nums[i], i + nums[i], position);
            if (i + nums[i] >= position) {
                position = i;
                steps += 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0) { return 0; }
        printf("-- end %d--\n", position);
    }
    return steps;
}

/**
 方法二，贪心算法
 顺序查找，贪心，找到跳到最远的距离，通过更新 rightMost 找到最远距离
 
 nums[0]=1, 0 < 1 , end = 0
  most= 1, end=1, steps=1
 nums[1]=3, 1 < 4 , end = 1
  most= 4, end=4, steps=2
 nums[2]=2, 4 < 4 , end = 4
  most= 4, end=4, steps=2
 nums[3]=9, 4 < 12 , end = 4
  most= 12, end=4, steps=2
 nums[4]=0, 12 < 4 , end = 4
  most= 12, end=12, steps=3
 nums[5]=0, 12 < 5 , end = 12
  most= 12, end=12, steps=3
 */
int jump(int* nums, int numsSize){
    
    int rightMost = 0, steps = 0, end = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        
        printf(" nums[%d]=%d, %d < %d , end = %d\n", i, nums[i], rightMost, i + nums[i], end);
        rightMost = rightMost < i + nums[i] ? i + nums[i] : rightMost;
        if (end == i) { //这可以算为一步
            end = rightMost; steps += 1;
        }
        printf("  most= %d, end=%d, steps=%d\n", rightMost, end, steps);
        
    }
    
    return steps;
}


int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,2,9,0,0,0};
    printf("ans = %d\n", jump(a, 7));
//    int a[] = {0,1};
//    printf("ans = %d\n", jump(a, 2));
    
    return 0;
}
















