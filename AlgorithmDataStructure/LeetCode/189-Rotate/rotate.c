
#include <stdio.h>
#include <stdlib.h>


//方法一、暴力解法，每次移动一个。移动 k 次
void rotate0(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2 || k < 1) { return; }
    
    int count = k%numsSize;
    if (count == 0) { return; }
    
    for (int i = 0; i < count; i++) {
        int temp = nums[numsSize - 1];
        for (int j = numsSize - 1; j > 0; j--) {
            nums[j] = nums[j-1];
        }
        nums[0] = temp;
    }
}

//方法二、另开新数组，保存数据
void rotate1(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2 || k < 1) { return; }
    
    int count = k%numsSize;
    if (count == 0) { return; }
    
    int *a = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        a[(i+count)%numsSize] = nums[i];
    }
    
    for (int i = 0; i < numsSize; i++) {
        nums[i] = a[i];
    }
    free(a);
}


//方法三、旋转数组
/**
 1、整个旋转   7 6 5 4 3 2 1
 2、旋转前 k 个  5 6 7
 3、旋转后 n-k个 5 6 7 1 2 3 4
 */

void reverse(int *nums, int numsSize, int start) {
    int i = start, j = numsSize - 1, temp = 0;
    while (i < j) {
        temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
        i++; j--;
    }
}

void rotate2(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2 || k < 1) { return; }
    
    int count = k%numsSize;
    if (count == 0) { return; }
    
    reverse(nums, numsSize, 0);
    reverse(nums, count, 0);
    reverse(nums, numsSize, count);
}


//方法四、环状替代
void rotate(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2 || k < 1) { return; }
    
    k = k%numsSize;
    if (k == 0) { return; }
    
    int count = 0;
    
    //这个循环防止，挤出的那一个，正好和现在的互换了。
    //相当于没有人被挤出去，就 ++
    for (int i = 0; count < numsSize; i++) {
        int cur = i;
        int pre = nums[cur];//从这个开始跳到下一个。一个个的找下一个位置
        
        //下面的循环，是给挤出去的下一个找位置
        do {
            int next = (cur + k) % numsSize; //下一个
            int temp = nums[next]; //暂存下一个
            nums[next] = pre;
            pre = temp;
            cur = next;
            count++;
        } while (i != cur);
    }
    
}


int main(int argc, const char * argv[]) {
    int nums[] = {1,2,3,4,5,6,7};
    rotate(nums, 7, 3);
    for (int i = 0; i < 7; i++) {
        printf(" %d ", nums[i]);
    }
    printf("\n");
    return 0;
}



