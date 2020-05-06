
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 取前后两个标志点，然后取后面的字符在这个区间里对比，
 如有重复的调整区间的大小，找到区间最大值返回
 
 滑动窗口
 */

int lengthOfLongestSubstring(char * s){
    unsigned long length = strlen(s);
    if (length < 2) {
        return (int)length;
    }
    
    int start = 0, end = 1, count = end - start, flag;
    char c1;
    for (int i = 1; i < length; i++) {
        c1 = s[i];
        flag = -1;
        for (int j = start; j < end; j++) {
            char c2 = s[j];
            if (c1 == c2) {
                flag = j;
                break;
            }
        }
        //printf("%d = %c --- %d - %d = %d %d\n", i, c1,end, start,count, flag);
        if (flag != -1) {
            start = flag + 1;
        }
        end += 1;
        if (count < end - start) {
            count = end - start;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    char *s = "bbbbbb";
    int a = lengthOfLongestSubstring(s);
    printf("result = %d\n", a);
    return 0;
}



