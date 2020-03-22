

#include <stdio.h>
#include <stdbool.h>


//方法一，数学方法


//辗转相除法，求最大公因子
int m_gcd(int x, int y) {
    printf("%d %d\n", x, y);
    return y == 0 ? x : m_gcd(y, x%y);
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) { return  false; }
    if (z == 0) { return true; }
    if (x == 0 || y == 0) { return z == 0 || x + y == z; }
    return z % m_gcd(x, y) == 0;
    
}

int main(int argc, const char * argv[]) {
    printf("ans = %d\n", canMeasureWater(3, 5, 4));
    return 0;
}






