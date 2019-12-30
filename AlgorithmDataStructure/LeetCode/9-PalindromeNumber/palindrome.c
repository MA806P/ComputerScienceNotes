#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    int num = x, a[10] = {-1}, i = 0;
    while (num != 0) {
        a[i] = num%10;
        i++;
        num /= 10;
    }
    long reverseInt = 0;
    for (int j = 0; j < i; j++) {
        reverseInt = reverseInt*10 + a[j];
    }
    return reverseInt == x;
}
*/

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    int num = x;
    long reverseInt = 0;
    while (num > 0) {
        reverseInt = reverseInt*10 + num%10;
        num /= 10;
    }
    return reverseInt == x;
}

int main(int argc, const char * argv[]) {
    
    printf("%d\n",isPalindrome(0));
    printf("%d\n",isPalindrome(-121));
    printf("%d\n",isPalindrome(12344321));
    //printf("%d\n",isPalindrome(12345654321));
    // 1 0 1
    
    return 0;
}
