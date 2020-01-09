
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int expandAroundCenter(char *s, int left, int right) {
    long length = strlen(s);
    while (left >= 0 && right < length && s[left] == s[right]) {
        left -= 1;
        right += 1;
    }
    return right - left - 1;
}

char *longestPalindrome(char * s){
    if (s == NULL || strlen(s) < 1) {
        return "";
    }
    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i++) {
        int l1 = expandAroundCenter(s, i, i);
        int l2 = expandAroundCenter(s, i, i + 1);
        int l = l1 > l2 ? l1 : l2;
        //printf("i = %d, %d, %d, %d - %d = %d\n", i, l, l/2, end, start, end - start);
        if (l > end - start) {
            start = i - (l - 1)/2;
            end = i + l/2;
        }
    }
    //printf("%d, %d\n", start, end);
    int length = end - start + 1;
    char *result = malloc((length + 1)*sizeof(char));
    strncpy(result, s + start, length);
    result[length] = '\0';
    return result;
}



int main(int argc, const char * argv[]) {
    
    char *s = "0123432109";
    printf("--%s \n", longestPalindrome(s));
    
    return 0;
}

