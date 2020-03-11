

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * addBinary(char * a, char * b){
    long  al = strlen(a);
    if (a == NULL || al <= 0) { return b; }
    long  bl = strlen(b);
    if (b == NULL || bl <= 0) { return a; }
    
    long l = al > bl ? al : bl;
    char *res = (char *)malloc(sizeof(char) * (l + 2));
    for (long i = 0; i < l+2; i++) {
        res[i] = '\0';
    }
    
    int flag = 0, sum = 0, a1 = 0, b1 = 0;
    for (long i = 0; i < l + 1; i++) {
        
        if (flag == 0 && al < 1 && bl < 1) { break; }
        a1 = al > 0 ? a[al - 1] - '0' : 0;
        b1 = bl > 0 ? b[bl - 1] - '0' : 0;
        al--; bl--;
        
        sum = a1 + b1 + flag;
        res[i] = (sum % 2) + '0';
        flag = sum > 1 ? 1 : 0;
    }
    
    //翻转一下
    long resL = strlen(res);
    for (long i = 0; i < resL/2; i++) {
        char temp = res[i];
        res[i] = res[resL - i - 1];
        res[resL - i - 1] = temp;
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    
    char *a = "1011";
    char *b = "111";
    
    printf("%s\n", addBinary(a, b));
    return 0;
}




