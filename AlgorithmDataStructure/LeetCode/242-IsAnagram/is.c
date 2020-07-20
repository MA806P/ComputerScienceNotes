
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//快速排序
//选择一元素(一般是最后一个)作为分界点，分界点前比它小，后面都是比它大的
//然后子分区继续这样分，直到最后只有一个元素
void swap_item(char *a, char *b) { char temp = *a; *a = *b; *b = temp; }
long partition(char *array, long p, long r) {
    long i = p;
    for (long j = p; j < r; j++) {
    //这里把大于 r 位的数，换到后面，小的换到前面
    //保证了，i 位前的都小于 r，i 位是第一个大于 r 的，遍历完 i r 互换
        if (array[j] < array[r]) {
            if (i != j) { swap_item(array + i, array + j); }
            i++;
        }
    }
    swap_item(array + i, array + r);
    return i;
}
void quick_sort(char *array, long p, long r) {
    if (p >= r) { return; }
    long q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
}



bool isAnagram0(char * s, char * t){
    if (s == NULL || t == NULL) { return false; }
    long sl = strlen(s), tl = strlen(t);
    if (sl != tl) { return false; }
    
    char *tempS = (char *)malloc(sizeof(char)*(sl+1));
    strcpy(tempS, s);
    
    char *tempT = (char *)malloc(sizeof(char)*(tl+1));
    strcpy(tempT, t);
    
    quick_sort(tempS, 0, sl - 1);
    quick_sort(tempT, 0, tl - 1);
    
    int ans = strcmp(tempS, tempT);
    printf("%s  %s  %d\n", tempS, tempT, ans);
    free(tempS);
    free(tempT);
    return ans == 0;
}



//方法二，26 个字母统计次数
//题目说明，你可以假设字符串只包含小写字母。
bool isAnagram(char * s, char * t){
    if (s == NULL || t == NULL) { return false; }
    long sl = strlen(s), tl = strlen(t);
    if (sl != tl) { return false; }
    
    int map[26] = {0};
    
    for (long i = 0; i < sl; i++) {
        map[s[i]-'a'] += 1;
        map[t[i]-'a'] -= 1;
    }
    
    for (int i = 0; i < 26; i++) {
        if (map[i] != 0) return false;
        
    }
    
    return true;
}


int main(int argc, const char * argv[]) {
    
    char *s = "anagram";
    char *t = "nagarbm";
    printf("%s  %s\n", s, t);
    printf("ans = %d \n", isAnagram(s, t));
    
}



