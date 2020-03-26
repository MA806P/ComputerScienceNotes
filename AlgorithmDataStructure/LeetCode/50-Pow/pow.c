
#include <stdio.h>
//方法一、暴力循环
double myPow0(double x, int n){
    //if (n == 0) { return 1.0; }
    //if (x == 0 || x == 1) { return x; }
    //if (x == -1) { return n%2 == 0 ? 1.0 : x;}
    
    long tn = n;
    if (tn < 0) {
        x = 1/x;
        tn = -tn;
    }
    
    double ans = 1;
    for (long i = 0; i < tn; i++) {
        ans *= x;
    }
    return ans;
}


//方法二、递归
/*
 pow(2,10) = 32*32 = 1024
 pow(2,5)  = 4*4*2 = 32
 pow(2,2)  = 2*2* = 4
 pow(2,1)  = 1*1*2 = 2
 pow(2,0)  = 1
 */
double halfPow(double x, long n){
    printf("%ld, %ld\n", n, n/2);
    if (n == 0) { return 1.0; }
    double half = halfPow(x, n/2);
    if (n %2 == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}
double myPow1(double x, int n){
    long tn = n;
    if (tn < 0) {
        x = 1/x;
        tn = -tn;
    }
    return halfPow(x, tn);
}


//方法三、循环
double myPow(double x, int n){
    long tn = n;
    if (tn < 0) {
        x = 1/x;
        tn = -tn;
    }
    
    double ans = 1, cur = x;
    for (long i = tn; i > 0; i /= 2) {
        if (i % 2 == 1) {
            ans *= cur;
        }
        cur = cur * cur;
        printf("%ld = %lf  %lf\n", i, ans, cur);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    printf("%lf\n", myPow(2, 10));
   
    
    return 0;
}






