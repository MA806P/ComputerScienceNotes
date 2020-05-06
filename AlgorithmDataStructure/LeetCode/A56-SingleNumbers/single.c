

#include <stdio.h>
#include <stdlib.h>

/**
 
 分组，相同的数分成一组，不同的数分为一组
 
 1、全员异或 [1,2,10,4,1,4,3,3] = 不同的两个数的异或 = 2^10
 2、在异或结果中找到任意为 1 的位
 3、根据这一位对所有数字进行分组，在每组中进行异或操作，得到两个数字
 
 */

int* singleNumbers(int* nums, int numsSize, int* returnSize){
    
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    int ret = 0;
    //全员异或
    for (int i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }
    
    //在异或结果中找到任意为 1 的位
    int div = 1;
    while ((div & ret) == 0) {
        //div 左移一位，
        //将异或好的值的二进制从右往左第一个为1的位找出来
        //例如 ret = 1^3 = 0001^0011 = 0010
        // div&ret = 0001&0010 = 0000 == 0  -->   div<<1 = 0010
        // div&ret = 0010&0010 = 1  -->   div = 0010
        div <<= 1;
    }
    
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        //根据该位是否为 0 将数组分为两组
        // [2,2,1,3]  div == 0010
        // div&2 = 0010&0010 = 0   a=0^2=2  a=2^2=0010^0010=0
        // div&1 = 0010&0001 = 0   b=0^1=1
        // div&3 = 0010&0011 = 2   a=0^3=3
        if (div & n) {
            a ^= n;
        } else {
            b ^= n;
        }
    }
    
    ans[0] = a; ans[1] = b;
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,10,4,1,4,3,3};
    
    int returnSize = 0;
    int *ans = singleNumbers(a, 8, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
















