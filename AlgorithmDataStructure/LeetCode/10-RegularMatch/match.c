
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p){
    int sLength = (int)strlen(s), pLength = (int)strlen(p);
    if (pLength == 0) {
        return sLength == 0;
    }
    //先比较第一位的情况
    bool firstMatch = sLength > 0 && (p[0] == s[0] || p[0] == '.');
    //* 会出现第二个位置，出现后连带前一个字符，和对应的s位置比较，
    //如果第一位相等 s+1 继续比较
    //如果第一位不相等忽略 p+2 继续比较
    if (pLength >= 2 && p[1] == '*') {
        return isMatch(s , p + 2) || (firstMatch && isMatch(s + 1, p));
    } else {
        return firstMatch && isMatch(s + 1, p + 1);
    }
}

int main(int argc, const char * argv[]) {
    
//    char *s = "mississippi";
//    char *p = "mis*is*p*.";
//    printf("%d\n", isMatch(s, p));
    
//    char *s = "aaa";
//    char *p = "aaaa";
//    printf("%d\n", isMatch(s, p)); //0
    
//    char *s = "aa";
//    char *p = ".aa";
//    printf("%d\n", isMatch(s, p)); //0
    
    char *s = "aaa";
    char *p = "ab*a*c*a";
    printf("%d\n", isMatch(s, p)); //1
    
    //aaa  aaaa 0
    //aaa  ab*a*c*a 1
    
    
    return 0;
}


