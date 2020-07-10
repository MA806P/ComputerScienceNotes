
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//暴力，两次循环，超时
bool containsDuplicate0(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return false; }
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}



//快速排序
//选择一元素(一般是最后一个)作为分界点，分界点前比它小，后面都是比它大的
//然后子分区继续这样分，直到最后只有一个元素
void swap_item(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
int partition(int *array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
    //这里把大于 r 位的数，换到后面，小的换到前面
    //保证了，i 位前的都小于 r，i 位是第一个大于 r 的，遍历完 i r 互换
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



//先排序，然后查重
bool containsDuplicate(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return false; }
    
    quick_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int nums[4] = {1,2,3,1};
    printf("ans = %d \n", containsDuplicate(nums, 4));
    return 0;
}



