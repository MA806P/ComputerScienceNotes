
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverseString(char s[], long start, long end) {
    while (start < end) {
        char temp = s[start]; s[start] = s[end]; s[end] = temp;
        start += 1; end -= 1;
    }
}

char * reverseWords(char * s) {
    long sl = strlen(s);
    if (sl < 1) { return s; }
    
    
    char *temps = (char *)malloc(sizeof(char) * sl);
    strcpy(temps, s);
    reverseString(temps, 0, sl - 1);
    
    long start = 0;
    for (long i = 0; i < sl; i++) {
        if (i == sl - 1 || temps[i+1] == ' ') {
            reverseString(temps, start, i); start = i + 2;
        }
    }
    
    char *ans = (char *)malloc(sizeof(char) * sl);
    memset(ans, '\0', sizeof(char) * sl);
    int needSpace = 0, index = 0;
    for (long i = 0; i < sl; i++) {
        if (temps[i] != ' ') {
            ans[index] = temps[i]; index++; needSpace = 1;
        } else if (needSpace == 1) {
            ans[index] = ' '; index++; needSpace = 0;
        }
    }
    if (index > 0 && ans[index - 1] == ' ') { ans[index - 1] = '\0'; }
    free(temps);
    return ans;
}

int main(int argc, const char * argv[]) {
    
    char *s = " abcdefg     hijkl   ";
    printf("ans = --%s--\n", reverseWords(s));
    
    return 0;
}





