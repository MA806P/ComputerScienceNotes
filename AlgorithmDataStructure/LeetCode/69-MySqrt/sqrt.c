
#include <stdio.h>
#include <math.h>


//方法一，只要求是整数
int mySqrt0(int x){
    if (x < 2) { return x; }
    
    int i = 1;
    while (i*i <= x) {
        //超过int最大值溢出了为负的
        if (i*i <= 0) { break; }
        i++;
    }
    return --i;
}

//方法二，公式
int mySqrt1(int x){
    if (x < 2) { return x; }
    
    //sqrt(x) = e^(logx / 2)
    int left = (int)pow(exp(1), 0.5 * log(x));
    int right = left + 1;
    return (long)right *right > x ? left : right;
}


//方法三，二分叉查找
int mySqrt2(int x){
    if (x < 2) { return x; }
    
    long num = 0;
    int pivot = 0, left = 2, right = x/2;
    while (left <= right) {
        pivot = left + (right - left)/2;
        num = (long)pivot*pivot;
        if (num > x) {
            right = pivot - 1;
        } else if (num < x) {
            left = pivot + 1;
        } else {
            return pivot;
        }
    }
    return right;
}

//方法三，牛顿迭代法
int mySqrt(int x){
    if (x < 2) { return x; }
    
    double x0 = x;
    double x1 = (x0 + x/x0) / 2.0;
    while (fabs(x0 - x1) >= 1) {
        printf("%.4lf  %.4lf\n", x0, x1);
        x0 = x1;
        x1 = (x0 + x/x0)/2.0;
        printf("%.4lf\n", x1);
    }
    return (int)x1;
}


int main(int argc, const char * argv[]) {
    
    printf("%d\n", mySqrt(2147483647));
    
    return 0;
}




