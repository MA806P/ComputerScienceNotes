
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//方法一，用数组记录使用次数
int countCharacters0(char ** words, int wordsSize, char * chars){
    if (words == NULL || wordsSize <= 0) { return 0; }
    
    int ans = 0;
    long charsL = strlen(chars);
    int *charsFlag = (int *)malloc(sizeof(int) * charsL);
    
    for (int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int wordL = (int)strlen(word);
        int isAns = 1;
        for (int i = 0; i < charsL; i++) { charsFlag[i] = 0; }
        for (int j = 0; j < wordL; j++) {
            char wc = word[j]; int isExist = 0;
            for (int l = 0; l < charsL; l++) {
                if (charsFlag[l] == 0 && chars[l] == wc) {
                    charsFlag[l] = 1; isExist = 1; break;
                }
            }
            if (isExist == 0) { isAns = 0; break; }
        }
        if (isAns == 1) { ans += wordL; }
    }
    free(charsFlag);
    return ans;
}

//方法二，用二十六个字母记录字母使用次数
int countCharacters(char ** words, int wordsSize, char * chars) {
    if (words == NULL || wordsSize <= 0) { return 0; }
    
    int ans = 0;
    int charFlag[26] = {0};
    long charsL = strlen(chars);
    for (int i = 0; i < charsL; i++) {
        charFlag[chars[i] - 'a'] += 1;
    }
    
    for (int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int wordL = (int)strlen(word);
        if (wordL > charsL) { continue; }
        int isAns = 1;
        
        int wordFlag[26] = {0};
        
        for (int j = 0; j < wordL; j++) {
            wordFlag[word[j] - 'a'] += 1;
        }
        for (int l = 0; l < 26; l++) {
            if (charFlag[l] < wordFlag[l]) {
                isAns = 0; break;
            }
        }
        if (isAns == 1) { ans += wordL; }
    }
    return ans;
}




int main(int argc, const char * argv[]) {
    
    char **s = (char **)malloc(sizeof(char *)*4);
    s[0] = "cat";
    s[1] = "bt";
    s[2] = "hat";
    s[3] = "tree";
    char *cs = "atach";
    printf("%d\n", countCharacters(s, 4, cs));
    
    return 0;
}




