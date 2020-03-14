
#include <stdio.h>


void swap_item(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
int partition(int *array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
        if (array[j] < array[r]) {
            if (i != j) { swap_item(array + i, array + j); }
            i++;
        }
    }
    swap_item(array + i, array + r);
    return i;
}
void quick_sort(int *array, int p, int r) {
    if (p >= r) { return; }
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
}



//给定一个大小为 n 的数组，找到其中的多数元素。
//多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//注意: 出现次数 > n/2，这个是关键

//方法一，排序之后下标为 n/2 的元素一定是众数。
int majorityElement0(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    
    //快速排序
    quick_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    //排序之后下标为 n/2 的元素一定是众数。
    return nums[numsSize/2];
}

//方法二， Boyer-Moore 投票算法
//把众数记为 +1，其他数记为 -1，全部加起来和 > 0
int majorityElement(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    
    int count = 0, candidate = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate ? 1 : -1);
    }
    
    return candidate;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,2,3,2,4};
    printf("%d\n", majorityElement(a, 6));
    
    return 0;
}




