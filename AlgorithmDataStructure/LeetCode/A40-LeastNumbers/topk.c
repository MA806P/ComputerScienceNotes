
#include <stdio.h>
#include <stdlib.h>


//方法一、先给数组排序，取前 K 个就是，最小的 K 个数

//方法二、使用大根堆。最大的数总是在堆顶，堆中放K个数，然后遍历剩余的数，比对顶小的替换掉


//方法三、利用快排的思想。 不断的划分数组，找到某一位，前面有 k 个小的数
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


void quick_selected(int *array, int p, int r, int k) {
    if (p >= r ) { return; }
    
    //初始 p=0 r=arrSize-1
    //取最后一位为基准，找到 q 位，使得 q 前的数小于最后一位
    int q = partition(array, p, r);
    
    
    
    if (k == q) {
        //划分后，正好前面是，前 k 小的数
        return;
    } else if (k < q) {
        //前 k 小的数在 0-q 这个范围内，比 k 多。继续划分。
        quick_selected(array, p, q - 1, k);
    } else {
        //前 k 小的，一部分全部在 0-q ，比 k 少，另一部分在 q-r
        quick_selected(array, q + 1, r, k);
    }
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (arr == NULL || arrSize <= 0 || k < 0) { return NULL; }
    
    //递归，不断的划分数组，找到某一位，前面有 k 个小的数
    //arr 交换变化了
    quick_selected(arr, 0, arrSize - 1, k);
    
    
    
    int *ans = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        ans[i] = arr[i];
    }
    *returnSize = k;
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int a[] = {0,1,1,2,4,4,1,3,3,2};
    int size = 0;
    int *ans = getLeastNumbers(a, 10, 6, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}






