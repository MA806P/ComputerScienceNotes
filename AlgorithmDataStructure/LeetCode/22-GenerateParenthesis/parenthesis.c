
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ** generateParenthesis(int n, int* returnSize){
    
    if (n == 0) {
        char **returnArray = (char **)malloc(sizeof(char *));
        returnArray[0] = "";
        *returnSize = 1;
        return returnArray;
    }
    if (n == 1) {
        char **returnArray = (char **)malloc(sizeof(char *));
        returnArray[0] = "()";
        *returnSize = 1;
        return returnArray;
    }
    
    char ***dp = (char ***)malloc(sizeof(char **) * (n + 1));
    int *dpSize = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = (char **)malloc(sizeof(char *));
    dp[0][0] = "";
    dpSize[0] = 1;
    
    dp[1] = (char **)malloc(sizeof(char *));
    dp[1][0] = "()";
    dpSize[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = (char **)malloc(sizeof(char *) * 10000);
        int size = 0;
        
        for (int j = 0; j < i; j++) {
            int p = j;
            int q = i - 1 - j;
            char **item1 = dp[p];
            char **item2 = dp[q];
            for (int x = 0; x < dpSize[p]; x++) {
                for (int y = 0; y < dpSize[q]; y++) {
                    char *temp = (char *)malloc(sizeof(char) * i * 2 + 1);
                    strcpy(temp, "(");
                    strcat(temp, item1[x]);
                    strcat(temp, ")");
                    strcat(temp, item2[y]);
                    temp[i*2] = '\0';
                    
                    dp[i][size] = temp;
                    size++;
                    //printf("** %s %d\n", temp, size);
                }
            }
        }
        dpSize[i] = size;
    }
   
    /*
    for (int i = 0; i < n; i++) {
        char **array = dp[i];
        int size = dpSize[i];
        for (int j = 0; j < size; j++) {
            char *item = array[j];
            free(item);
        }
        free(array);
    } */
    
    *returnSize = dpSize[n];
    free(dpSize);
    return dp[n];
}

int main(int argc, const char * argv[]) {
    
    int size;
    char **result = generateParenthesis(4, &size);
    for (int i = 0; i < size; i++) {
        char *item = result[i];
        printf("%d -- %s\n", i, item);
    }
    
    return 0;
}




