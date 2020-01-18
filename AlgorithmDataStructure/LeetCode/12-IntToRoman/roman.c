
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
char * intToRoman(int num) {
    //char result[20] = {'\0'};
    char *result = (char *)malloc(20 * sizeof(char));
    for (int i = 0; i < 20; i++) {
        result[i] = '\0';
    }
    
    
    if (num >= 1000) {
        int a = num/1000;
        for (int i = 0; i < a; i++) {
            strcat(result, "M");
        }
        num = num%1000;
    } else if (num >= 100) {
        int b = num/100;
        if (b == 10) {
            strcat(result, "M");
        } else if (b == 9) {
            strcat(result, "CM");
        } else if (b >= 5) {
            strcat(result, "D");
            for (int i = 0; i < b - 5; i++) {
                strcat(result, "C");
            }
        } else if (b == 4) {
            strcat(result, "CD");
        } else {
            for (int i = 0; i < b; i++) {
                strcat(result, "C");
            }
        }
        num = num%100;
    } else if (num >= 10) {
        int c = num/10;
        if (c == 10) {
            strcat(result, "C");
        } else if (c == 9) {
            strcat(result, "XC");
        } else if (c >= 5) {
            strcat(result, "L");
            for (int i = 0; i < c - 5; i++) {
                strcat(result, "X");
            }
        } else if (c == 4) {
            strcat(result, "XL");
        } else {
            for (int i = 0; i < c; i++) {
                strcat(result, "X");
            }
        }
        num = num%10;
    } else {
        int d = num%10;
        if (d == 10) {
            strcpy(result, "X");
        } else if (d == 9) {
            strcpy(result, "IX");
        } else if (d >= 5) {
            strcpy(result, "V");
            for (int i = 0; i < d - 5; i++) {
                strcat(result, "I");
            }
        } else if (d == 4) {
            strcpy(result, "IV");
        } else {
            for (int i = 0; i < d; i++) {
                strcat(result, "I");
            }
        }
        return result;
    }
    return strcat(result, intToRoman(num));
}
 */


char * intToRoman(int num) {
    
    char items[13][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *result = (char *)malloc(20 * sizeof(char));
    for (int i = 0; i < 20; i++) {
        result[i] = '\0';
    }
    
    for (int i = 0; num != 0; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(result, items[i]);
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    printf("%s\n", intToRoman(3));
    printf("%s\n", intToRoman(4));
    printf("%s\n", intToRoman(9));
    printf("%s\n", intToRoman(58));
    printf("%s\n", intToRoman(1994));
    
    return 0;
}




