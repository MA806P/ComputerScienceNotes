
#include <stdio.h>

//直接计算，这个很暴力。计算到20就溢出了
int trailingZeroes0(int n){
    if (n < 5) { return 0; }
    
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    printf("result = %ld\n", result);
    
    int ans = 0;
    while (result%10 == 0) {
        ans++;
        result /= 10;
    }
    return ans;
}

//这个很逗
int trailingZeroes1(int n){
    return n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625
    +n/1953125+n/9765625+n/48828125 + n/244140625 + n/1220703125;
}


/**
 5! = 1*2*3*4*5
 要想找阶乘后面的 0，就是分解看看有多少个 2*5，
 阶乘分解开，看 2 的数量更定多于 5 的数量
 所以最后就是找，一共能分解出多少个 5
 */
int trailingZeroes2(int n){
    if (n < 5) { return 0; }
    
    int ans = 0, temp = 0;
    for (int i = 5; i <= n; i++) {
        temp = i;
        while (temp%5 == 0) {
            ans += 1; temp /= 5;
        }
    }
    return ans;
}

/**
 上面的方法去找 5 的个数，提交会超时 O(n)
 要想时间复杂度为 O(log n) 。
 一个个除以 5 很低效
 
 n 每隔 5 个数出现一个 5，除以 5 之后又是每隔 5 个数出现一个 5
 就是 n/5 + n/25 + n/125 + ...
 例如 25! , 5*10*15*20*25 == 5*1 * 5*2 * 5*3 * 5*4 * 5*5 六个5
25/5  == 5
25/25 = (25/5)/5 == 1
其实就是上面投机取巧的方法。这个自己想，怎么能想到。。
 
 */
int trailingZeroes(int n){
    int ans = 0, temp = n;
    while (temp > 0) {
        temp /= 5; ans += temp;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    printf("ans = %d\n", trailingZeroes(25));
    return 0;
}



