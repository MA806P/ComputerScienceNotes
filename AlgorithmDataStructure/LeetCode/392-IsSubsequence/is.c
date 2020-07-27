
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//方法一、双指针
bool isSubsequence(char * s, char * t){
    if (s == NULL || t == NULL) { return  false; }
    long sl = strlen(s), tl = strlen(t);
    
    long si = 0, ti = 0;
    while (ti < tl && si < sl) {
        if (t[ti] == s[si]) { si++; }
        ti++;
    }
    printf("%ld==%ld  %ld==%ld\n", ti, tl, si, sl);
    return si == sl;
}

//方法二、动态规划
bool isSubsequence0(char * s, char * t){
    
    int sl = (int)strlen(s), tl = (int)strlen(t);
    int map[tl+1][26];
    memset(map, 0, sizeof(map));
    
    for (int i = 0; i < 26; i++) {
        map[tl][i] = tl;
    }
    
    //map 用来记录，t 每位字母的位置，以及在当前位置其他字母的最近位置
    for (int i = tl - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (t[i] == j + 'a') {
                map[i][j] = i;
            } else {
                map[i][j] = map[i + 1][j];
            }
        }
    }
    
    for (int i = 0; i < tl; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    int add = 0;
    for (int i = 0; i < sl; i++) {
        if (map[add][s[i] - 'a'] == tl) {
            return false;
        }
        add = map[add][s[i] - 'a'] + 1;
    }
    return true;
}





int main(int argc, const char * argv[]) {
    
    char *s = "children";
    char *t = "this is childrens father";
    printf("s = %s, t = %s\n", s, t);
    printf("ans = %d\n", isSubsequence0(s, t));
    return 0;
}



