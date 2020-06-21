
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isChar(char a) {
    if ((a>47&&a<58) || (a>64&&a<91) || (a>96&&a<123)) {
        return true;
    }
    return false;
}

bool isCharEqual(char a, char b) {
    if (a == b || a + 32 == b || a - 32 == b) {
        return true;
    } else if ((a>64&&a<91) && (b>96&&b<123) && b - a == 32) {
        return true;
    } else if ((b>64&&b<91) && (a>96&&a<123) && a - b == 32) {
        return true;
    }
    return false;
}

bool isPalindrome(char * s){
    if (s == NULL) { return false; }
    long sl = strlen(s);
    if (sl < 1) { return false; }
    
    bool ans = true;
    long start = 0, end = sl - 1;
    char a, b;
    while (start < end) {
        
        a = s[start];
        if (!isChar(a)) {
            start++; continue;
        }
        b = s[end];
        if (!isChar(b)) {
            end--; continue;
        }
        //printf("s[%ld]=%c,  s[%ld]=%c\n", start, a, end, b);
        if (!isCharEqual(a, b)) {
            ans = false; break;
        } else {
            start++; end--;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    char *s = "A man, a plan, a canal: Panama";
    printf("ans = %d\n", isPalindrome(s));
    return 0;
}



