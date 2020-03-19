

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_item(char *a, char *b) { char temp = *a; *a = *b; *b = temp; }
int partition(char *array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
        if (array[j] < array[r]) {
            if (i != j) { swap_item(array + i, array + j); }
            i++;
        }
    }
    swap_item(array + i, array + r);
    return i;
}
void quick_sort(char *array, int p, int r) {
    if (p >= r) { return; }
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
}

//方法一，先排序，然后计算相同字母的个数
int longestPalindrome0(char * s){
    if (s == NULL) { return 0; }
    int sl = (int)strlen(s);
    if (sl < 2) { return sl; }
    
    char *tempS = (char *)malloc(sizeof(char) * sl);
    for (int i = 0; i < sl; i++) {
        tempS[i] = s[i];
    }
    quick_sort(tempS, 0, sl - 1);
    
    int ans = 0;
    for (int i = 1; i < sl; i++) {
        printf("%d=%c %d=%c %d\n", i-1,tempS[i - 1], i ,tempS[i], ans);
        if (tempS[i] == tempS[i - 1]) {
            ans += 2; i += 1;
        }
    }
    if (ans < sl) { ans += 1; } //ans计算的重复的，是偶数，回文串中间还能插入一个单个的字符
    return ans;
}

//方法二，用一数组记录，字符出现的次数，然后计算次数偶数
int longestPalindrome(char * s){
    if (s == NULL) { return 0; }
    int sl = (int)strlen(s);
    if (sl < 2) { return sl; }
    
    int count[58] = { 0 }; //由于字符串只包含大小写字母，A-Z=65-90  a-z=97-122
    for (int i = 0; i < sl; i++) {
        count[s[i] - 'A'] += 1;
    }
    
    int ans = 0;
    for (int i = 1; i < 58; i++) {
        ans += count[i]/2 * 2;
    }
    if (ans < sl) { ans += 1; }  //回文串中间还能插入一个单个的字符
    return ans;
}



int main(int argc, const char * argv[]) {
    
    char *s = "abccccdd";
    printf("ans = %d\n", longestPalindrome(s));
    
    return 0;
}




