
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool isIsomorphic(char * s, char * t){
    
    long sl = strlen(s);
    long tl = strlen(t);
    if (sl != tl) { return false; }
    
    int sflag[255] = {0};
    char *sResult = (char *)malloc(sizeof(char) * (sl+1));
    memset(sResult, '\0', sizeof(char) *(sl+1));
    
    int tflag[255] = {0};
    char *tResult = (char *)malloc(sizeof(char) *(sl+1));
    memset(tResult, '\0', sizeof(char) *(sl+1));
    
    int sCount = 1, tCount = 1;
    for (long i = 0; i < sl; i++) {
        if (sflag[s[i]] == 0) {
            sflag[s[i]] = sCount;
            sCount++;
        }
        sResult[i] = sflag[s[i]] + '1';
        
        if (tflag[t[i]] == 0) {
            tflag[t[i]] = tCount;
            tCount++;
        }
        tResult[i] = tflag[t[i]] + '1';
    }
    
    int ans = strcmp(sResult, tResult);
    printf("%s=%s, %s=%s;  cmp=%d\n", s,sResult, t,tResult, ans);
    
    return ans == 0;
}


int main(int argc, const char * argv[]) {
    printf("ans = %d \n", isIsomorphic("egg", "aww"));
    return 0;
}



