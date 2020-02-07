
#include <stdlib.h>
#include <stdio.h>

//快慢指针
int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            if (i < j) {
                nums[i] = nums[j];
            }
            i++;
        }
    }
    return i;
}

/*
int removeElement(int* nums, int numsSize, int val){
    int i = 0, n = numsSize;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n-1];
            n--;
        } else {
            i++;
        }
    }
    return n;
} */

int main(int argc, const char * argv[]) {
    
    int nums[] = {0,0,1,1,1,1,1,1,1,2,2,3,3,4};
    int a = removeElement(nums, 14, 1);
    printf("--- %d\n", a);
    
    for (int i = 0; i < 10; i++) {
        printf(" %d", nums[i]);
    }
    
    return 0;
}



