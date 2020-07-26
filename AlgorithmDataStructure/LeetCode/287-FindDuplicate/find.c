
#include <stdio.h>


//方法一，二分法
/**
 n+1 个整数数组，其中的数字都在 1..n 之间，只有一个重复的数，可能重复多次
 
 先统计，数组中值<=下标 的个数
 例如数组有5个数，在 1..4之间  [1,2,3,4,2]
 下标0，小于等于0的数有 0 个
 下标1，小于等于1的数有 1 个
 下标2，小于等于2的数有 3 个
 下标3，小于等于1的数有 4 个
 下标4，小于等于1的数有 5 个
 cnt = [0,1,3,4,5]
 然后对，cnt 进行二分查找，
 mid=2  ==>   cnt=3 > mid=2   high = mid-1 = 1  ans = 2
 
 
 如果数组没有重复的 [1,2,3,4,5]
 cnt = [0,1,2,3,4,5]
 
 如果重复的是 3  [1,2,3,3,4]
 cnt = [0,1,2,4,5]  ans = 3
 
 如果重复的是 4 [1,2,3,4,4]
  cnt = [0,1,2,3,5]  ans = 4
 
 看到规律了吧，就是找 cnt 中 0..n 缺失的那个数
 
 */
int findDuplicate(int* nums, int numsSize){
    
    int low = 0, high = numsSize - 1;
    int mid = 0, cnt = 0, ans = -1;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        cnt = 0;
        
        for (int i = 0; i < numsSize; i++) {
            cnt += nums[i] <= mid;
        }
        
        if (cnt <= mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = mid;
        }
    }
    return ans;
}


//方法二、快慢指针
/**
 数组建图，每个位置 i 连一条 i→nums[i] 的边。
 [4,3,2,1,3]  4->3<->1    2<->指向自己   可能产生多个链表，组成图
 [4,3,2,3,1]  4->1->3<->3  2<->
 
 由于存在的重复的数字 target，因此 target 这个位置一定有起码两条指向它的边，
 因此整张图一定存在环，且我们要找到的 target 就是这个环的入口，那么整个问题就等价于 142. 环形链表 II。
 
 
 */
int findDuplicate0(int* nums, int numsSize){
    
    int slow = 0, fast = 0;
    
    //找到快慢指针相遇点
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    //找到相遇点之后，
    //为什么后面将 slow 放置起点后移动相遇的点就一定是答案了?
    //[4,3,2,1,3]  4->3<->1    2<->指向自己   可能产生多个链表，组成图
    //[4,3,2,3,1]  4->1->3<->3  2<->
    //[4,3,2,1,2]  4->2<->2    3<->1
    //看看上面两个例子能不能想明白
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int main(int argc, const char * argv[]) {
    int nums[] = {1,3,4,4,2};
    printf("ans = %d\n", findDuplicate(nums, 5));
    return 0;
}



