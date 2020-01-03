#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize <= 0) {
        return "";
    }
    
    char *baseChars = strs[0];
    int endIndex, baseCount = (int)strlen(baseChars);
    endIndex = baseCount;
    for (int i = 1; i < strsSize; i++) {
        char *item = strs[i];
        for (int j = 0; j < baseCount; j++) {
            //printf("--%d %d %c %c--\n", j, endIndex, baseChars[j], item[j]);
            if (item[j] == '\0') {
                endIndex = endIndex > j ? j : endIndex;
                break;
            } else if (baseChars[j] != item[j]) {
                if (j == 0) {
                    return "";
                } else {
                    endIndex = endIndex > j ? j : endIndex;
                    break;
                }
            }
        }
    }
    
    char *result = (char *)malloc((endIndex+1) * sizeof(char));
    strncpy(result, baseChars, endIndex);
    result[endIndex] = '\0';
    return result;
}


int main(int argc, const char * argv[]) {
    
    char *a1[] = {"flower","flow","flight"};
    printf("--%s--\n", longestCommonPrefix(&(*a1), 3));
    
    char *a2[] = {"dog","racecar","car"};
    printf("--%s--\n", longestCommonPrefix(&(*a2), 3));
    
    char *a3[] = {"aac","acab","aa","abba","aa"};
    printf("--%s--\n", longestCommonPrefix(&(*a3), 5));
    
    
//    char *result = (char *)malloc((2+1) * sizeof(char));
//    strncpy(result, "abcdefg", 2);
//    result[2] = '\0';
//    printf("--%s--\n", result);//ab
    
    return 0;
}

