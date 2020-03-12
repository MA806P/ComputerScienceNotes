
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



//辗转相除法，求最大公因子
int m_gcd(int a, int b) {
    //printf("%d %d\n", a, b);
    return b == 0 ? a : m_gcd(b, a % b);
}


//判断字符串最大公因子能否拼接成字符串
bool check(char *t, char *s) {
    int sl = (int)strlen(s);
    char *ans = (char *)malloc(sizeof(char)*(sl+1));
    for (int i = 0; i < sl+1; i++) { ans[i] = '\0'; }
    
    int xl = sl / (int)strlen(t);
    for (int i = 1; i <= xl; i++) { strcat(ans, t); }
    return strcmp(ans, s) == 0;
}

//方法一，枚举
char * gcdOfStrings0(char * str1, char * str2) {
    int l1 = (int)strlen(str1), l2 = (int)strlen(str2);
    
    //两个字符串长度的最大公约数，就是要求得字符串长度
    int xl = m_gcd(l1, l2);
    char *res = (char *)malloc(sizeof(char) * (xl + 1));
    for (int i = 0; i < xl+1; i++) { res[i] = '\0'; }
    
    strncpy(res, str1, xl);//根据长度截取字符串
    if (check(res, str1) && check(res, str2)) {
        return res;
    } else {
        return "";
    }
    
}


//方法二
char * gcdOfStrings(char * str1, char * str2) {
    int l1 = (int)strlen(str1), l2 = (int)strlen(str2);
    
    
    char *res1 = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
    for (int i = 0; i < l1 + l2 + 1; i++) { res1[i] = '\0'; }
    strcpy(res1, str1);
    strcat(res1, str2);
    
    char *res2 = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
    for (int i = 0; i < l1 + l2 + 1; i++) { res2[i] = '\0'; }
    strcpy(res2, str2);
    strcat(res2, str1);
    
    //如果 str1 + str2 != str2 + str1 则肯定不存在最大公因子
    if (strcmp(res1, res2) != 0) {
        return "";
    }
    
    //如果 str1 + str2 == str2 + str1，则肯定存在，直接截取就行了
    //两个字符串长度的最大公约数，就是要求得字符串长度
    int xl = m_gcd(l1, l2);
    char *ans = (char *)malloc(sizeof(char) * (xl + 1));
    for (int i = 0; i < xl+1; i++) { ans[i] = '\0'; }
    
    strncpy(ans, str1, xl);//根据长度截取字符串
    return ans;
    
}




int main(int argc, const char * argv[]) {
    
    char *a = "12121212";
    char *b = "1212";
    printf("%s\n", gcdOfStrings(a, b));
    
    //printf("%d\n", check("12", "ababab"));
    
    return 0;
}




