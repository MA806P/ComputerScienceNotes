
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//一开始的想法有点蠢。没想到，所有的数组和平分三份。
//遍历一遍就行了。累加到三分之一，然后再累加到三分之一，直到结束
bool canThreePartsEqualSum0(int* A, int ASize){
    if (A == NULL || ASize < 3) { return false; }
    
    int temp = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < ASize; i++) { temp += A[i]; }
    
    for (int i = 0; i < ASize - 2; i++) {
        sum1 += A[i];
        sum2 = 0;
        sum3 = temp - sum1;
        for (int j = i + 1; j < ASize - 1; j++) {
            sum2 += A[j];
            sum3 -= A[j];
            printf("%d %d %d\n", sum1, sum2, sum3);
            if (sum1 == sum2 && sum2 == sum3) { return true; }
        }
    }
    return false;
}


bool canThreePartsEqualSum(int* A, int ASize){
    if (A == NULL || ASize < 3) { return false; }
    
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) { return false; }
    int target = sum / 3;
    
    int partSum = 0, count = 0;
    for (int i = 0; i < ASize; i++) {
        partSum += A[i];
        if (partSum == target) {
            count++;
            if (count == 2) { return true; }
            partSum = 0;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int a[11] = {0,2,1,-6,6,-7,9,1,2,0,1};
    printf("%d\n", canThreePartsEqualSum(a, 11));
    return 0;
}





