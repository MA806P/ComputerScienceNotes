
#include <stdio.h>
#include <stdlib.h>


int* divingBoard(int shorter, int longer, int k, int* returnSize){
    
    if (k <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    if (shorter == longer) {
        int *ans = (int *)malloc(sizeof(int));
        *returnSize = 1;
        ans[0] = shorter * k;
        return ans;
    }
    
    *returnSize = k + 1;
    int *ans = (int *)malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; i++) {
        ans[i] = shorter * (k - i) + longer * i;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int size = 0;
    int *ans = divingBoard(2, 4, 10, &size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}



