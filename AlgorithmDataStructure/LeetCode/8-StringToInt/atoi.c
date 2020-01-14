
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int myAtoi(char * str){
    long length = strlen(str);
    if (length == 0) { return 0; }
    
    int sign = 1, flag = 0;
    long result = 0;
    for (int i = 0; i < length; i++) {
        char item = str[i];
        
        if (flag == 0) {
            if (item == '-') {
                sign = -1;
                flag = 1;
            } else if (item == '+') {
                flag = 1;
            } else if (item >= '0' && item <= '9') {
                result = item - 48;
                flag = 1;
            } else if (item == ' ') {
                continue;
            } else {
                return 0;
            }
        } else if (flag == 1) {
            if (item >= '0' && item <= '9') {
                result = result * 10 + item - 48;
                if (sign == 1 && result >= INT_MAX) {
                    return INT_MAX;
                } else if (sign == -1 && result - 1 >= INT_MAX) {
                    return INT_MIN;
                }
            } else {
                return (int)result * sign;
            }
        }
    }
    return (int)result * sign;
}

int main(int argc, const char * argv[]) {
    
    printf("==%d==\n", myAtoi("-2147483649"));
    //"  +42 ab 345"  42
    
    //"-2147483647"  -2147483647
    //"-2147483648"  -2147483648
    //"-2147483649"  -2147483648
    //"2147483648"  2147483647
    
    return 0;
}


