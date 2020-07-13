
#include <stdio.h>
#include <stdlib.h>

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

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1 == NULL || nums1Size <= 0 || nums2 == NULL || nums2Size <= 0) {
        return NULL;
    }
    
    quick_sort(nums1, 0, nums1Size - 1);
    quick_sort(nums2, 0, nums2Size - 1);
    
    int size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *ans = (int *)malloc(sizeof(int) * size);
    *returnSize = 0;
    
    int n1 = 0, n2 = 0;
    while (n1 < nums1Size && n2 < nums2Size) {
        if (nums1[n1] < nums2[n2]) {
            n1++;
        } else if (nums1[n1] > nums2[n2]) {
            n2++;
        } else {
            ans[*returnSize] = nums1[n1];
            (*returnSize) += 1;
            n1++; n2++;
        }
    }
    return ans;
}




int main(int argc, const char * argv[]) {
    
    int nums1[4] = {1,0,4,9};
    int nums2[2] = {4,9};
    printf("{1,0,4,9}   {4,9} \n");
    
    int ansSize = 0;
    int *ans = intersect(nums1, 4, nums2, 2, &ansSize);
    for (int i = 0; i < ansSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}



