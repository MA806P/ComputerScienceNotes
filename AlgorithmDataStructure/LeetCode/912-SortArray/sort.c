

#include <stdio.h>


void swap_int(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int parition(int *a, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
        if (a[j] < a[r]) {
            if ( i != j) { swap_int(a + i, a + j); }
            i++;
        }
    }
    swap_int(a + i, a + r);
    return i;
}
void quick_sort(int *a, int p, int r) {
    if (p >= r) { return; }
    int q = parition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (nums == NULL || numsSize < 2) { return nums; }
    
    quick_sort(nums, 0, numsSize - 1);
    return nums;
}


int main(int argc, const char * argv[]) {
    
    int a[5] = {2,5,1,4,3};
    int l = 0;
    
    int *b = sortArray(a, 5, &l);
    for (int i = 0; i < l; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}




