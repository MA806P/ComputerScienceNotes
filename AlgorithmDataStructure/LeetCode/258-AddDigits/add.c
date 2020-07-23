
#include <stdio.h>


int addDigits0(int num){
    if (num < 10) { return num; }
    
    int ans = num;
    while (ans >= 10) {
        ans = 0;
        while (num != 0) {
            ans += num%10;
            num /= 10;
        }
        num = ans;
    }
    return ans;
}


/**
x*100+y*10+z=x*99+y*9+x+y+z
 (x*99+y*9+x+y+z)%9 = x+y+z
*/
int addDigits(int num){
    if (num < 10) { return num; }
    return (num - 1) % 9 + 1;
}

int main(int argc, const char * argv[]) {

    
    
    printf("ans = %d\n", addDigits(49));
    return 0;
}



