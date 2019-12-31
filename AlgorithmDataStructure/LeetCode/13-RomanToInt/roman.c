#include <stdlib.h>
#include <stdio.h>

int romanToInt(char * s){
    int i = 0, sum = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case 'I': {
                if (s[i+1] != '\0') {
                    if (s[i+1] == 'V') {
                        sum += 4;
                        i++;
                    } else if (s[i+1] == 'X') {
                        sum += 9;
                        i++;
                    } else {
                        sum += 1;
                    }
                } else {
                    sum += 1;
                }
                break;
            }
            case 'V':
                sum += 5;
                break;
            case 'X': {
                if (s[i+1] != '\0') {
                    if (s[i+1] == 'L') {
                        sum += 40;
                        i++;
                    } else if (s[i+1] == 'C') {
                        sum += 90;
                        i++;
                    } else {
                        sum += 10;
                    }
                } else {
                    sum += 10;
                }
                break;
            }
            case 'L':
                sum += 50;
                break;
            case 'C': {
                if (s[i+1] != '\0') {
                    if (s[i+1] == 'D') {
                        sum += 400;
                        i++;
                    } else if (s[i+1] == 'M') {
                        sum += 900;
                        i++;
                    } else {
                        sum += 100;
                    }
                } else {
                    sum += 100;
                }
                break;
            }
            case 'D':
                sum += 500;
                break;
            case 'M':
                sum += 1000;
                break;
            default:
                break;
        }
        i++;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", romanToInt("III")); //3
    printf("%d\n", romanToInt("IV")); //4
    printf("%d\n", romanToInt("IX")); //9
    printf("%d\n", romanToInt("LVIII")); //58
    printf("%d\n", romanToInt("MCMXCIV")); //1994
    return 0;
}
