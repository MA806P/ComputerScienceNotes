
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//字符串翻转
void reverse(char *str, int left, int right) {
    int i = left, j = right - 1;
    while (i < j) {
        char a = str[i];
        str[i] = str[j];
        str[j] = a;
        i++; j--;
    }
}

char * convertToTitle(int n){
    if (n <= 0) { return ""; }
    char *ans = (char *)malloc(sizeof(char) * 100);
    memset(ans, '\0', sizeof(char)* 100);
    
    int a = n, count = 0;
    while (a > 0) {
        a -= 1; //注意需要 -1，26-z,27-aa, 28-ab, 相当于 9  10  11 中间少了10 直接到 11
        int b = a%26;
        ans[count] = 'A' + b;
        count++;
        a /= 26;
    }
    reverse(ans, 0, count);
    return ans;
}


int main(int argc, const char * argv[]) {
    int a = 701;
    printf("%d = %s\n", a, convertToTitle(a));
    return 0;
}



