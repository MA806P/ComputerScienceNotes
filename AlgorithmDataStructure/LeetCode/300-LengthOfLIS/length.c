
#include <stdio.h>
#include <stdlib.h>


//方法一，动态规划
/*
 取后面固定位置，从前遍历小于它的最大值+1
        10  9  2  5  3  7  101  18  6
 dp    1   1  1  2  2  3   4      4   3
 max = 4
 
*/
int lengthOfLIS0(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return numsSize; }
    
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    dp[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = 0;
    }
    
    int maxval = 0, maxans = 0;
    for (int i = 1; i < numsSize; i++) {
        maxval = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                //这里是>，不要>=，[2,2]=>1
                maxval = maxval < dp[j] ? dp[j] : maxval;
            }
        }
        dp[i] = maxval + 1;
        maxans = maxans < dp[i] ? dp[i] : maxans;
    }
    free(dp);
    return maxans;
}


//方法二，贪心算法+二分查找
/*
 贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
 因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
 10,9,2,5,3,7,101,18
 
 num = 10   [0,10]
 num = 9     [0,9]  替换 10
 num = 2     [0,2]   替换 9
 num = 5     [0,2,5] 直接添加
 num = 3     [0,2,3] 替换 5
 num = 7     [0,2,3,7]  直接添加
 num = 101  [0,2,3,7,110] 直接添加
 num = 18    [0,2,3,7,18] 替换 101
 len = 4
 */
int lengthOfLIS(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return numsSize; }
    
    int *d = (int *)malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++) {
        d[i] = 0;
    }
    int len = 1;
    d[len] = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > d[len]) {
            len += 1;
            d[len] = nums[i];
        } else {
            //这个数小，按顺序插入到 d 中
            int left = 1, right = len, mid = 0, pos = 0;
            while (left <= right) {
                mid = left + (right - left)/2;
                if (d[mid] < nums[i]) {
                    pos = mid;  left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            //如果 d 中的数都比 nums[i] 大  pos=0 更新 d[1]=nums[i]
            //如果 d 中的数都比 nums[i] 小 不会进入这个条件，上面条件直接拼到后面
            //如果 d[倒数第二个] < num[i] < d[倒数第一个]   更新 d[倒数第一个]= num[i]
            //如果有重复的插入，会替换重复的，不会同时保留两个
            d[pos + 1] = nums[i];
            
            printf("%d =",i);
            for (int j = 0; j < numsSize + 1; j++) {
                printf(" %d ", d[j]);
            }
            printf("\n");
        }
    }
    
    free(d);
    return len;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {10,9,2,5,3,7,101,18};
    printf("%d\n", lengthOfLIS(a, 8));
    
    return 0;
}




