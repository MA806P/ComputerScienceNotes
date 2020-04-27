

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    int num = 1;
    while (n > 0) { num *= n--; }
    return num;
}

void deleteItem(int *nums, int numsSize, int in) {
    while (in < numsSize - 1) {
        nums[in] = nums[in + 1]; in += 1;
    }
}
char *getPermutation(int n, int k) {
    int i, j = 0, nums[n], factor;
    char *res = (char *)calloc(10, sizeof(char));
    for (i = 0; i < n; i++) {
        //初始化一个 [1,2,3,……,n] 数组
        nums[i] = i + 1;
    }
    
    for (i = 0, k--; i < n; i++) {  //k要先减去1
        factor = factorial(n - i - 1);
        res[j++] = nums[k / factor] + '0';
        deleteItem(nums, n - i, k / factor);  //取出一个元素
        k %= factor;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    
    printf("%s\n", getPermutation(4, 9));
    
    return 0;
}





















