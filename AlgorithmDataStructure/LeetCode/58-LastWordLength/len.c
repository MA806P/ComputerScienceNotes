
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s){
    long len = strlen(s);
    if (s == NULL || len == 0) { return 0; }
    int res = 0;
    for (long i = len - 1; i >=0; i--) {
        
        if (s[i] == ' ' && res > 0) {
            break;
        }
        if (s[i] != ' ') {
            res++;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    char *s = "12 12     ";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}












