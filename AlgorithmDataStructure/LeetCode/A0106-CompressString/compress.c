
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *intToStr(int n) {
    if (n == 0) { return "0"; }
    char *s = (char *)malloc(sizeof(char) * 12);
    for (int i = 0; i < 12; i++) {
        s[i] = '\0';
    }
    
    int a = n, r = 0, l = 0;
    if (a < 0) {
        s[0] = '-';
        l = r = 1;
        a *= -1;
    }
    
    while (a > 0) {
        s[r++] = a%10 + '0';
        a = a/10;
    }
    
    r--;
    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++; r--;
    }
    
    return s;
}


char* compressString(char* S){
    int sl = (int)strlen(S);
    if (S == NULL || sl < 2) { return S; }
    
    char *ans = (char *)malloc(sizeof(char) * 50000);
    for (int i = 0; i < 50000; i++) {
        ans[i] = '\0';
    }
    
    int count = 1, index = 0;
    for (int i = 0; i < sl; i++) {
        if (i + 1 < sl && S[i] == S[i+1]) {
            count++;
        } else {
            ans[index++] = S[i];
            if (count < 10) {
                ans[index++] = count + '0';
            } else {
                char *intStr = intToStr(count);
                strcat(ans, intStr);
                index += strlen(intStr);
                free(intStr);
            }
            count = 1;
        }
    }
    return strlen(ans) > sl ? S : ans;
}

int main(int argc, const char * argv[]) {
    
    char *a = "abbeeeeeeeeeeeed";
    printf("%s\n", compressString(a));
    
    printf("%s\n", intToStr(10));
    
    return 0;
}





