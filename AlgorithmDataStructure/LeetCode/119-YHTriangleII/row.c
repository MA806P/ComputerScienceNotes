
#include <stdio.h>
#include <stdlib.h>
/**
 1
 1   1
 1   2   1
 1   3   3   1
 1   4   6   4   1
 */



int* getRow(int rowIndex, int* returnSize){
    
    *returnSize = rowIndex + 1;
    int *ans = (int *)malloc(sizeof(int *) * (*returnSize));
    
    for (int i = 0; i <= rowIndex; i++) {
        ans[i] = 1; //末尾为1
        for (int j = i; j > 1; j--) {
            //从后往前算，当前位加上前一位，和覆盖当前位
            ans[j - 1] = ans[j-1] + ans[j-2];
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int returnSize = 0;
    
    int *ans = getRow(6, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}



