

#include <stdio.h>
/*
 例如当数组 A 为 [1, 1, 1, 1, 3, 5] 时，我们发现有 3 个重复的 1，且没有出现过 2，4 和 6，
 因此一共需要进行 (2 + 4 + 6) - (1 + 1 + 1) = 9 次操作。
 */
int minIncrementForUnique(int* A, int ASize){
    if (A == NULL || ASize < 2) { return 0; }
    
    int count[80000] = {0};
    for (int i = 0; i < ASize; i++) {
        count[A[i]]++;
    }
    
    int ans = 0, taken = 0;
    for (int i = 0; i < 80000; i++) {
        if (count[i] >= 2) {
            taken += count[i] - 1;
            ans -= i * (count[i] - 1);
        } else if (taken > 0 && count[i] == 0) {
            taken--;
            ans += i;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int a[] = {3,2,1,2,1,7};
    
    printf("ans = %d\n", minIncrementForUnique(a, 6));
    return 0;
}





