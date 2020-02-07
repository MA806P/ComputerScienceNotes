
//
//  main.c

#include <stdlib.h>
#include <stdio.h>

/*
 int removeDuplicates(int* nums, int numsSize){
     int returnSize = numsSize, i = 1;
     while (i < returnSize) {
         int a0 = nums[i - 1], a1 = nums[i];
         if (a0 == a1) {
             for (int j = i; j < returnSize - 1; j++) {
                 nums[j] = nums[j + 1];
             }
             returnSize--;
         } else {
             i++;
         }
     }
     return returnSize;
 }
 */
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) { return 0; }
    
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            if (i < j) {
                nums[i] = nums[j];
            }
        }
    }
    return i + 1;
}



int main(int argc, const char * argv[]) {
    
    int nums[] = {0,0,1,1,1,1,1,1,1,2,2,3,3,4};
    int a = removeDuplicates(nums, 14);
    printf("--- %d\n", a);
    
    for (int i = 0; i < 10; i++) {
        printf(" %d", nums[i]);
    }
    
    return 0;
}



