
#include <stdio.h>
#include <stdbool.h>


int bitSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int temp = n % 10;
        n = n / 10;
        sum += temp * temp;
    }
    return sum;
}

bool isHappy0(int n){
    while (n != 1) {
        if (n == 4 || n == 16 || n == 37 || n == 58 || n == 89 || n == 145 || n == 42 || n == 20) {
            return false;
        }
        n = bitSquareSum(n);
    }
    return true;
}



//快慢指针法
bool isHappy(int n){
    
    int slow = n;
    int fast = bitSquareSum(n);
    while (fast != 1 && slow != fast) {
        slow = bitSquareSum(slow);
        fast = bitSquareSum(bitSquareSum(fast));
    }
    return fast == 1;
}


int main(int argc, const char * argv[]) {
    
    printf("ans = %d\n", isHappy(19));
    return 0;
}

















