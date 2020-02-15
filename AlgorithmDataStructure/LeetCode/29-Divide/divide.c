
#include <stdio.h>

/*
 int tempDiv(long a, long b) {
         if ( a < b ) return 0;
         long count = 1;
         long tb = b;
         while((tb+tb)<=a) {
             count = count + count;
             tb = tb+tb;
         }
         return (int)(count + tempDiv(a-tb,b));
 }

 int divide(int dividend, int divisor){
     
     if (dividend == 0 ) { return 0; }
     if (divisor == 1) { return dividend; }
     if (divisor == -1) {
         if (dividend > -2147483648) { return -dividend; }
         return 2147483647;
     }
     if (dividend == divisor) { return 1; }

     int sign = 1;
     if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
         sign = -1;
     }
     
     long a = dividend;
     long b = divisor;
     a = a > 0 ? a : -a;
     b = b > 0 ? b : -b;
     if (a < b) { return 0; }
     
     int res = tempDiv(a, b);
     return sign > 0 ? res : -res;
 }
 
 */


int divide(int dividend, int divisor){
    
    if (dividend == 0 ) { return 0; }
    if (divisor == 1) { return dividend; }
    if (divisor == -1) {
        if (dividend > -2147483648) { return -dividend; }
        return 2147483647;
    }
    if (dividend == divisor) { return 1; }
    

    int sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        sign = -1;
    }
    
    long a = dividend;
    long b = divisor;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    if (a < b) { return 0; }
    
    int res = 0;
    
    /*
     要求商，我们首先想到的是减法，能被减多少次，那么商就为多少，但是明显减法的效率太低
     那么我们可以用位移法，因为计算机在做位移时效率特别高，向左移1相当于乘以2，向右位移1相当于除以2
     我们可以把一个dividend（被除数）先除以2^n，n最初为31，不断减小n去试探,当某个n满足dividend/2^n>=divisor时，
     表示我们找到了一个足够大的数，这个数*divisor是不大于dividend的，所以我们就可以减去2^n个divisor，以此类推

     我们可以以100/3为例
     2^n是1，2，4，8...2^31这种数，当n为31时，这个数特别大，100/2^n是一个很小的数，肯定是小于3的，所以循环下来，
     当n=5时，100/32=3, 刚好是大于等于3的，这时我们将100-32*3=4，也就是减去了32个3，接下来我们再处理4，同样手法可以再减去一个3
     所以一共是减去了33个3，所以商就是33

     */
    for (int i = 31; i >= 0; i--) {
        if ((a >> i) >= b) {//找出足够大的数2^n*divisor
            res += ((unsigned int)1) << i;//将结果加上2^n
            a -= b << i;//将被除数减去2^n*divisor
        }
    }
    
    return sign > 0 ? res : -res;
}




int main(int argc, const char * argv[]) {
    
    printf("-- %d\n", divide(-2147483648, 2));
    return 0;
}


