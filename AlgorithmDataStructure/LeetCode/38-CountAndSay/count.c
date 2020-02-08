
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * countAndSay(int n){
    
    char *a = (char *)malloc(sizeof(char) * 10000);
    char *str = (char *)malloc(sizeof(char) * 10000);
    str[0] = '1';
    for (int i = 1; i < 10000; i++) {
        str[i] = '\0';
    }
    
    for (int l = 1; l < n; l++) {
        int count = 1, index = 0;
        for (int i = 0; i < strlen(str); i++) {
            if ( i + 1 < strlen(str) && str[i] == str[i+1]) {
                count++;
            } else {
                a[index++] = '0' + count;
                a[index++] = str[i];
                count = 1;
            }
        }
        strncpy(str, a, index);
        //printf("%d = 1 = %s  2 = %s  3 = %d\n", l,str, a, index);
    }
    free(a);
    return str;
}

int main(int argc, const char * argv[]) {
    
    printf("-- %s\n", countAndSay(5));
    
    return 0;
}




