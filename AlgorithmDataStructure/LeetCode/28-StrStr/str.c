
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    long needleL = strlen(needle);
    if (needleL <= 0) { return 0; }
    long strL = strlen(haystack);
    if (strL <= 0) { return -1; }
    
    int a = -1;
    for (int i = 0; i < strL - needleL + 1; i++) {
        if (haystack[i] == needle[0]) {
            
            a = i;
            for (int j = 1; j < needleL; j++) {
                if (haystack[i+j] != needle[j]) {
                    a = -1;
                    break;
                }
            }
            if (a != -1) {
                return a;
            }
        }
    }
    
    return a;
}


int main(int argc, const char * argv[]) {
    
    char *str = "hello";
    char *needle = "llo";
    printf("-- %d\n", strStr(str, needle));
    
    return 0;
}



