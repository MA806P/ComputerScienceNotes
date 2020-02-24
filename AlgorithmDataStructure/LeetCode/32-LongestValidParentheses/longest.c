
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char  DATATYPE;
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
void stackPopAll(stack *s) {
    while (s->next != NULL) {
        stackPop(s);
    }
}

int longestValidParentheses(char * s){
    long len = strlen(s);
    if (len == 0 || len == 1) { return 0; }
    
    int result = 0, count = 0;
    stack *st = stackCreate();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            if (st->next == NULL) {
                stackPush(st, s[i]);
            } else if (count > 0) {
                stackPopAll(st);
                result = result > count ? result : count;
                count = 0;
                stackPush(st, s[i]);
            }
        } else if (s[i] == ')') {
            if (st->next == NULL) {
                result = result > count ? result : count;
                count = 0;
            } else if (st->next->data == '(') {
                count += 2;
                stackPop(st);
            }
        }
    }
    stackDestroy(st);
    return result > count ? result : count;;
}


int main(int argc, const char * argv[]) {
    
    char *s = "()()(()((()))";
    printf(" = %d\n", longestValidParentheses(s));
    return 0;
}






