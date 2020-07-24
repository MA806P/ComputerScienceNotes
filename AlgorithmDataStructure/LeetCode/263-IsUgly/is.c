
#include <stdio.h>
#include <stdbool.h>
/**
 是否为丑数。
 丑数就是只包含质因数 2, 3, 5 的正整数。
 */
bool isUgly0(int num){
    if (num <= 0) { return false; }
    
    int count[] = {2,3,5};
    for (int i = 0; i < 3; i++) {
        while (num%count[i] == 0) {
            num = num/count[i];
        }
    }
    if (num == 1) {
        return true;
    }
    return false;
}


bool isUgly(int num){
    if (num < 1) { return false; }
    if (num == 1) { return true; }
    
    if (num % 2 == 0) {
        num /= 2;
    } else if (num % 3 == 0) {
        num /= 3;
    } else if (num % 5 == 0) {
        num /= 5;
    } else {
        return false;
    }
    return isUgly(num);
}

int main(int argc, const char * argv[]) {
    printf("ans = %d\n", isUgly(49));
    return 0;
}



