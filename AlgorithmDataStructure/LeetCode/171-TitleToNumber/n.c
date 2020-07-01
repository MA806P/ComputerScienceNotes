
#include <stdio.h>
#include <string.h>


int titleToNumber0(char * s){
    if (s == NULL) { return 0; }
    
    int sl = (int)strlen(s);
    int ans = 0;
    for (int i = 0; i < sl; i++) {
        int count = sl - 1 - i, m = 1;
        while (count > 0) {
            m *= 26; count--;
        }
        ans += (s[i] - 'A' + 1) * m;
    }
    return ans;
}


/**
 ans = ans * 26 + s[i] - 'A' + 1;
 不要这样连着写，不然会溢出 "FXSHRXW" = 2147483647
2147483624 + 87 - ‘A’ + 1 前面算到 +87 已经溢出了
 */
int titleToNumber(char * s){
    if (s == NULL) { return 0; }
    
    int sl = (int)strlen(s);
    int ans = 0;
    for (int i = 0; i < sl; i++) {
        int m = s[i] - 'A' + 1;
        ans = ans * 26 + m;
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    char *s = "ZY";
    printf("%s = %d\n", s, titleToNumber(s));
    return 0;
}



