
#include <stdlib.h>
#include <stdio.h>

int divide(int dividend, int divisor){
    
    if (dividend == 0) { return 0; }
    if (divisor == 1) { return dividend; }
    if (divisor == -1) {
        if (dividend > -2147483648) { return -dividend; }
        return 2147483647;
    }

    int sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        sign = -1;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);

    int result = 0, remainder = dividend - divisor;
    while (remainder >= divisor) {
        result++;
        dividend = remainder;
        remainder = dividend - divisor;
    }
    return result;
}

int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
}



int main(int argc, const char * argv[]) {
    
    printf("asdfasf\n");
    printf("-- %d\n", divide(6, 3));
    return 0;
}



