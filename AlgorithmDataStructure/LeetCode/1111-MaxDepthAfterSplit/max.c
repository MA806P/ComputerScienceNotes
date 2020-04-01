

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* maxDepthAfterSplit(char * seq, int* returnSize){
    
    int seql = (int)strlen(seq);
    
    int *res = (int *)malloc(sizeof(int)*seql);
    memset(res, 0, sizeof(int) * seql);
    *returnSize = seql;
    
    for (int i = 0; i < seql; i++) {
        char c =seq[i];
        printf("%d = %d\n", i, i & 1);
        res[i] = c == '(' ? ( i & 1) : ((i + 1) & 1);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    char *s = "()(()())";
    int l = 0;
    
    int *b = maxDepthAfterSplit(s, &l);
    for (int i = 0; i < l; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}




