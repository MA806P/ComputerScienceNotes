
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DATATYPE;
typedef struct _list_stack {
    DATATYPE data;
    struct _list_stack *next;
} stack;
stack *stackCreate() {
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) { return NULL; }
    s->next = NULL;
    return s;
}
void stackDestroy(stack *s) {
    stack *tempS = NULL;
    while (s->next != NULL) {
        tempS = s->next;
        s->next = tempS->next;
        free(tempS);
    }
    free(s);
}
void stackPush(stack *s, DATATYPE data) {
    stack *node = (stack *)malloc(sizeof(stack));
    if (node == NULL) { return; }
    node->data = data;
    node->next = s->next;
    s->next = node;
}
DATATYPE stackPop(stack *s) {
    if (s->next == NULL) { return 0; }
    stack *next = s->next;
    DATATYPE data = next->data;
    s->next = next->next;
    free(next);
    return data;
}
DATATYPE stackPeek(stack *s) {
    if (s->next == NULL) { return 0; }
    return s->next->data;
}

//首先将-1放入栈顶，遇到‘(’将下标入栈，
//遇到‘)’弹出栈顶元素，并将当前元素下标与栈顶的相减，得出当前有效长度，
//记录下最大值
int longestValidParentheses(char * s){
    int len = (int)strlen(s);
    if (len == 0 || len == 1) { return 0; }
    int max = 0;
    
    stack *st = stackCreate();
    stackPush(st, -1);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stackPush(st, i);
        } else if (s[i] == ')') {
            stackPop(st);
            if (st->next == NULL) {
                stackPush(st, i);
            } else {
                int temp = i - stackPeek(st);
                max = temp > max ? temp : max;
            }
        }
    }
    stackDestroy(st);
    return max;
}


//左右遍历
//两个计数器left=(的数，right=)的数，
//当 left=right 当前有效长度=left*2，如果left<right,都置为0。
//从左到右left<right = 0，从右到左 left>right = 0，遍历遍历两次，找到最大值
int longestValidParentheses1(char * s){
    int len = (int)strlen(s);
    if (len == 0 || len == 1) { return 0; }
    
    int max = 0, left = 0, right = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            left++;
        } else if (s[i] == ')'){
            right++;
        }
        if (left == right) {
            int temp = left * 2;
            max = temp > max ? temp : max;
        } else if (left < right) {
            left = right = 0;
        }
    }
    
    left = right = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else if (s[i] == ')'){
            right++;
        }
        if (left == right) {
            int temp = left * 2;
            max = temp > max ? temp : max;
        } else if (left > right) {
            left = right = 0;
        }
    }
    
    return max;
}


//动态规划方法
//以 ( 结尾的，肯定不是有效的括号 ...)(   ...((
//所以只要考虑结尾是 ) 的情况，这时有两种情况 ...()  ...))
int longestValidParentheses0(char * s){
    int len = (int)strlen(s);
    if (len == 0 || len == 1) { return 0; }
    
    int max = 0;
    int *dp = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) { dp[i] = 0; }
    
    for (int i = 1; i < len; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') {
                dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
            } else if (i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
                int temp = i - dp[i-1] - 2;
                dp[i] = dp[i-1] + (temp >= 0 ? dp[temp] : 0) + 2;
            }
            max = dp[i] > max ? dp[i] : max;
        }
    }
    return max;
}


int main(int argc, const char * argv[]) {
    
    char *s = "()()(()((()))";
    printf(" = %d\n", longestValidParentheses0(s));
    return 0;
}


