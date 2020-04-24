
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 //暴力解法超时
int reversePairs(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return 0; }
    int ans = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) { ans += 1; }
        }
    }
    return ans;
} */



//归并排序
void merge(int a[], int p, int q, int r) {
    int *tmp = malloc(sizeof(int) * (r - p + 1));
    if (!tmp) { abort(); }
    printf("%d %d %d\n", p,q,r);
    
    //合并两个分区的数组
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) { tmp[k++] = a[i++]; } else { tmp[k++] = a[j++]; }
    }
    //两个分区的数组长度可能不同，有一个数组遍历完了
    //然后下面将长的数组添加到后面
    if (i == q + 1) {
        while (j <= r) {  tmp[k++] = a[j++]; }
    } else {
        while (i <= q) { tmp[k++] = a[i++]; }
    }
    //将排序好的数组，复制到原来的数组上
    memcpy(a + p, tmp, (r - p + 1) * sizeof(int)); free(tmp);
}

/**
 7  5  6  4
 [7,5] [6,4]
 [7][5][6][4]
 合并
 [5,7] [4,6]
 [4,5,6,7]
 */
void merge_sort(int a[], int p, int r) {
    if (p >= r) { return; }
    //将数组一分为二，直到只有1个元素 //然后合并两个有序数组，递归
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}
void merge_sort_size(int a[], int size) {
    merge_sort(a, 0, size - 1);
}



/// 上面的是归并排序，下面是解题，思想是一样的 分治方法
/// 题目是要求，前面一个数字大于后面的数字，这样的逆序对的个数
/// 把数组二分，分到只有一个，然后再两两合并成有序的数组，在合并的过程中计算逆序对个数

//合并，并计算逆序对
int mergeAndCount(int *nums, int left, int mid, int right, int *temp) {
    for (int i = left; i <= right; i++) { temp[i] = nums[i]; }
    
    int i = left, j = mid + 1, count = 0;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) { //左边遍历完了
            nums[k] = temp[j]; j++;
        } else if (j == right + 1) { //右边遍历完了
            nums[k] = temp[i]; i++;
        } else if (temp[i] <= temp[j]) { //左 <= 右，顺序
            nums[k] = temp[i]; i++;
        } else {  //左 > 右，逆序，在这里计算逆序对
            nums[k] = temp[j]; j++;
            //看左边还有多少元素，有多少就说明有多少逆序对，想想似不似
            //这里是加速计算逆序对的关键，因为有序所以方便计算
            count += (mid - i + 1);
        }
    }
    return count;
}

//拆分
int reversePart(int *nums, int left, int right, int *temp) {
    if (left >= right) { return 0;}
    
    int mid = left + (right - left)/2;
    int leftPairs = reversePart(nums, left, mid, temp);
    int rightPairs = reversePart(nums, mid + 1, right, temp);
    if (nums[mid] <= nums[mid+1]) {
        return leftPairs + rightPairs;
    }
    int crossPairs = mergeAndCount(nums, left, mid, right, temp);
    return leftPairs + rightPairs + crossPairs;
}

int reversePairs(int* nums, int numsSize){
    if (nums == NULL || numsSize < 2) { return 0; }
    
    int *copyNums = (int *)malloc(sizeof(int) * numsSize);
    memcpy(copyNums, nums, sizeof(int) * numsSize);
    
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    return reversePart(copyNums, 0, numsSize - 1, temp);
}

int main(int argc, const char * argv[]) {
    
    int a[] = {7,5,6,4};
    printf("ans = %d\n", reversePairs(a, 4));
    return 0;
}









