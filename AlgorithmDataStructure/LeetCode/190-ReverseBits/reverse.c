
#include <stdio.h>

typedef unsigned int uint32_t;

//方法一、逐位颠倒。位操作
uint32_t reverseBits0(uint32_t n) {
    uint32_t ans = 0, power = 31;
    
    //从右到左遍历。n&1 只看最右的一位，其它位为 0
    //一次循环之后，处理下一位 n>>1
    while (n != 0) {
        ans += (n&1) << power;
        n = n >> 1;
        power -= 1;
    }
    
    return ans;
}

//方法二
/**
 将32位分为两个16位的，一个左移一个右移，然后再分成8位，直到1位。
 这个种方法，类似于前面一题 189. 旋转数组
 */
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}


int main(int argc, const char * argv[]) {
    
    uint32_t ans = reverseBits(1);
    printf("ans = %x\n", ans);
    return 0;
}



