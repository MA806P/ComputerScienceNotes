
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    if (digits == NULL || digitsSize <= 0) { return digits; }
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + 1 > 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            break;
        }
    }
    
    *returnSize = digitsSize;
    int *res = (int *)malloc(sizeof(int) * (digitsSize + 1));
    if (digits[0] == 0) {
        (*returnSize) += 1;
        res[0] = 1;
        for (int i = 0; i < digitsSize; i++) {
            res[i + 1] = digits[i];
        }
    } else {
        for (int i = 0; i < digitsSize; i++) {
            res[i] = digits[i];
        }
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    int n = 0;
    int a[2] = {9,9};
    
    int *r = plusOne(a, 2, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
    return 0;
}




