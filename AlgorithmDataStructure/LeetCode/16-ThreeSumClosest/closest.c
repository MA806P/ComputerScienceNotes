
#include <stdlib.h>
#include <stdio.h>


//快速排序
void swap_array(int *a, int *b) {
    int tmp = *a;
    *a = *b; *b = tmp;
}
int partition(int *arr, int p, int r) {
    int i, j;
    i = j = p;
    for(; j < r; j++) {
        if (arr[j] < arr[r]) {
            if (i != j) { swap_array(arr + i, arr + j); }
            i++;
        }
    }
    swap_array(arr + i, arr + r);
    return i;
}
void quick_sort(int *arr, int p, int r) {
    int q;
    if (p >= r) { return; }
    q = partition(arr, p, r);
    quick_sort(arr, p, q - 1);
    quick_sort(arr, q + 1, r);
}


/**
 先进行排序方便操作。
 然后在排序后的数组中，遍历固定一个数 i，然后两个指针移动 start = i + 1, end = length - 1
 然后根据三个数和 sum 判断移动指针
 如果 sum > target, end--
 如果 sum < target, start++
 如果 sum == target, 找到了直接返回
 
 时间复杂度 O(nlogn) + O(n^2) = O(n^2)
 
 */
int threeSumClosest(int* nums, int numsSize, int target) {
    
    if (numsSize < 3) { return 0; }
    
    //排序
    quick_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n--------- \n");
    
    int sum = 0, start = 0, end = 0;
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize; i++) {
        start = i + 1;
        end = numsSize - 1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (abs(target - sum) < abs(target - result)) {
                result = sum;
            }
            if (sum > target) {
                end--;
            } else if (sum < target) {
                start++;
            } else {
                return sum;
            }
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    int nums[] = {1,1,1,0};
    printf("---%d\n", threeSumClosest(nums, 4, -100));
    return 0;
}




