
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//一位一位的相乘，错位相加
//用一数组保存各位的值，最后转出字符串
char * multiply(char * num1, char * num2){
    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);
    if (len1 <= 0 || len2 <= 0) { return ""; }
    
    int *sums = (int *)malloc(sizeof(int) * (len1 + len2));
    for (int i = 0; i < (len1 + len2); i++) {
        sums[i] = 0;
    }
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int tempSum = (num1[i] - '0') * (num2[j] - '0');
            tempSum += sums[i+j+1];
            sums[i+j+1] = tempSum % 10;
            sums[i+j] += tempSum / 10; //前一位相加
        }
        
        for (int a = 0; a < len1+len2; a++) {
            printf("%d ", sums[a]);
        }
        printf("\n");
    }
    
    int n = 0;
    for (n = 0; n < len1 + len2; n++) {
        if (sums[n] != 0) { break; }
    }
    if (n == len1 + len2) { n -= 1; }
    
    char *res = (char *)malloc(sizeof(char) * (len1 + len2 - n + 1));
    res[len1 + len2 - n] = '\0';
    for (int i = 0; i < (len1 + len2 - n); i++) {
        res[i] = sums[n+i] + '0';
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    char *a = multiply("0", "0");
    char *b = multiply("123", "456");
    printf("0 x 0 = %s\n 123 x 456 = %s\n", a, b);
    return 0;
}












