
#include <stdlib.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)


int reverse(int x) {
    if ((x > 0 && x < 10) || (x < 0 && x > -10)) {
        return x;
    }
    int a, result = 0;
     while (x != 0) {
         a = x%10;
         if (result > INT_MAX/10 || result < INT_MIN/10) {
             return 0;
         }
         result = result * 10 + a;
         x /= 10;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
//    int a = reverse(123);
//    int b = reverse(1200);
//    int c = reverse(-789);
    
//    int a = reverse(10000001);
//    int b = reverse(10000);
//    int c = reverse(-1000);
    
    int a = reverse(2147483647);
    int b = reverse(-2147483648);
    int c = reverse(-2147483412);
    
    printf("%d   %d   %d  ", a, b, c);
    
    return 0;
}

