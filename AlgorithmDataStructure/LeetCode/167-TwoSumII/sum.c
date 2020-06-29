
#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    if (numbers == NULL || numbers <= 0) { return NULL; }
    
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = -1; ans[1] = -1;
    *returnSize = 2;
    
    int low = 0, high = numbersSize - 1;
    while (low < high) {
        int sum = numbers[low] + numbers[high];
        if (sum == target) {
            ans[0] = low + 1; ans[1] = high + 1; break;
        } else if (sum < target) {
            ++low;
        } else {
            --high;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int returnSize = 0;
    int numbers[] = {2,7,11,15};
    int *ans = twoSum(numbers, 4, 9, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d  ", ans[i]);
    }
    printf("\n");
    
    return 0;
}



