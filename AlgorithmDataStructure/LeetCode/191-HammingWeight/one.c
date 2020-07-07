
#include <stdio.h>

typedef unsigned int uint32_t;

int hammingWeight0(uint32_t n) {
    int ans = 0;
    while (n != 0) {
        if ((n&1) == 1) {
            ans += 1;
        }
        n >>= 1;
    }
    return ans;
}
int hammingWeight1(uint32_t n) {
    int ans = 0, mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n&mask) != 0) {
            ans += 1;
        }
        mask <<= 1;
    }
    return ans;
}

/**
 把数字最后一个 1 反转，并把答案加一。当数字变成 0 的时候偶，我们就知道它没有 1 的位了，此时返回答案。
 数字 n 中最低位的 1 总是对应 n - 1 中的 0 。将 n 和 n−1 与运算总是能把 n 中最低位的 1 变成 0 ，并保持其他位不变。
 */
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n != 0) {
        ans += 1;
        n &= (n-1);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int ans = hammingWeight(3);
    printf("ans = %d\n", ans);
    
    
    return 0;
}



