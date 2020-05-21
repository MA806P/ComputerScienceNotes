
#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return 0; }
    if (numsSize == 1) { return nums[0]; }
    
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,3,1,2};
    
    printf("ans = %d\n", singleNumber(a, 5));
    return 0;
}
