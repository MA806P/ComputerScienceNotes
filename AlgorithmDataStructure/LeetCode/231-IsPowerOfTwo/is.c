

#include <stdio.h>
#include <stdbool.h>

/**
 判断它是否是 2 的幂次方
 1 = 0001  & 0000 = 0
 2 = 0010  & 0001 = 0
 4 = 0100  & 0011 = 0
 8 = 1000  & 0111 = 0
 n & (n-1) == 0
 */
bool isPowerOfTwo(int n){
    if (n <= 0) { return false; }
    return (n & (n-1)) == 0;
}

int main(int argc, const char * argv[]) {
    printf("ans = %d \n", isPowerOfTwo(8));
    return 0;
}

