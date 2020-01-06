
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define listStackIsEmpty(stack) (stack->next == NULL)

typedef struct _list_stack {
    char data;
    struct _list_stack *next;
}listStack;


listStack *listStackCreate() {
    listStack *stack = NULL;
    stack = (listStack *)malloc(sizeof(listStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->next = NULL;
    return stack;
}

void listStackDestroy(listStack *stack) {
    listStack *tmpStack = NULL;
    while (!listStackIsEmpty(stack)) {
        tmpStack = stack->next;
        stack->next = tmpStack->next;
        free(tmpStack);
    }
    free(stack);
    return;
}

bool listStackPush(listStack *stack, char data) {
    listStack *node = (listStack *)malloc(sizeof(listStack));
    if (node == NULL) {
        return false;
    }
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    return true;
}

char listStackPop(listStack *stack) {
    if (listStackIsEmpty(stack)) {
        return '0';
    }
    char data;
    listStack *next = stack->next;
    data = next->data;
    stack->next = next->next;
    free(next);
    return data;
}

void listStackDump(listStack *stack) {
    if (listStackIsEmpty(stack)) {
        printf("stack is empty \n");
        return;
    }
    listStack *next = stack->next;
    while (next != NULL) {
        printf("data = %c\n", next->data);
        next = next -> next;
    }
    return;
}

bool isMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']')  || (a == '{' && b == '}');
}

bool isValid(char * s){
    listStack *stack = listStackCreate();
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        //printf("%c\n", c);
        if (listStackIsEmpty(stack)) {
            listStackPush(stack, c);
        } else if (isMatch(stack->next->data, c)) {
            listStackPop(stack);
        } else {
            listStackPush(stack, c);
        }
        //listStackDump(stack);
    }
    bool result = listStackIsEmpty(stack);
    listStackDestroy(stack);
    return result;
}


int main(int argc, const char * argv[]) {
    
    char *s1 = "([)";
    printf("%d\n", isValid(s1));
    
    char *s2 = "([)]";
    printf("%d\n", isValid(s2));

    char *s3 = "{[]}";
    printf("%d\n", isValid(s3));
    
    return 0;
}



