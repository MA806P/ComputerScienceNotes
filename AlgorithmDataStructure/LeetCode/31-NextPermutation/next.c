
#include <stdio.h>
#include <stdlib.h>

//交换数组某两个位置的数据
void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

//从某个位置翻转数组
void reverse(int *nums, int numsSize, int start) {
    int i = start, j = numsSize - 1;
    while (i < j) {
        swap(nums, i, j);
        i++; j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2) { return; }
    int i = numsSize - 2;
    while (i >= 0 &&  nums[i] >= nums[i+1]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, numsSize, i + 1);
}


int main(int argc, const char * argv[]) {
    int a[] = {1,8,4,7,6,5,3,1};
    nextPermutation(a, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    //1 8 5 1 3 4 6 7
    return 0;
}












