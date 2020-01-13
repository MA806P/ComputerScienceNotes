
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * convert(char * s, int numRows){
    int length = (int)strlen(s);
    if (length <= 1  || numRows <= 1 || length <= numRows) {
        return s;
    }
    char rows[numRows][length];
    int *rowIndexs = (int *)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rowIndexs[i] = 0;
    }
    int flag = 1, x = 0, y = 0;
    for (int i = 0; i < length; i++) {
        y = rowIndexs[x];
        rows[x][y] = s[i];
        rows[x][y+1] = '\0';
        rowIndexs[x] += 1;
        x += flag;
        if (x == numRows - 1 || x == 0) {
            flag *= -1;
        }
    }
    free(rowIndexs);
    
    char *result = malloc(sizeof(char) * (length + 1));
    result[length] = '\0';
    
    for (int j = 0; j < numRows; j++) {
        if (j == 0) {
            strcpy(result, rows[j]);
        } else {
            strcat(result, rows[j]);
        }
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    
    char *r = convert("1234567890", 3);
    printf("== %s\n", r);
    return 0;
}


