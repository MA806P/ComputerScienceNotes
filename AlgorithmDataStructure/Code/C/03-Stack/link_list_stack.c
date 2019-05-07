#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _link_list_stack {
    int data;
    struct _link_list_stack *next;
}linkListStack;

#define link_list_stack_is_empty(stack) (stack->next == NULL)

linkListStack *link_list_stack_create() {
    linkListStack *stack = NULL;
    stack = (linkListStack *)malloc(sizeof(linkListStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->next = NULL;
    return stack;
}

void link_list_stack_destory(linkListStack *stack) {
    linkListStack *tmpStack = NULL;
    while (!link_list_stack_is_empty(stack)) {
        tmpStack = stack->next;
        stack->next = stack->next->next;
        
        free(tmpStack);
    }
    free(stack);
    return;
}

bool link_list_stack_push(linkListStack *stack, int data) {
    
    linkListStack *linkListData = (linkListStack *)malloc(sizeof(linkListStack));
    if (linkListData == NULL) {
        return false;
    }
    linkListData->data = data;
    linkListData->next = stack->next;
    stack->next = linkListData;
    return true;
}

int link_list_stack_pop(linkListStack *stack) {
    
    if (link_list_stack_is_empty(stack)) {
        return -1;
    }
    
    int data = -1;
    linkListStack *linkListNext = stack->next;
    data = linkListNext->data;
    
    stack->next = linkListNext->next;
    free(linkListNext);
    return data;
}


void link_list_dump(linkListStack *stack) {
    if (link_list_stack_is_empty(stack)) {
        printf("stack is empty\n");
        return;
    }
    
    linkListStack *next = stack->next;
    while (next != NULL) {
        printf("stack data = %d\n", next->data);
        next = next->next;
    }
    return;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    linkListStack *stack = link_list_stack_create();
    
    link_list_stack_push(stack, 2);
    link_list_dump(stack);
    printf("\n");
    
    link_list_stack_push(stack, 3);
    link_list_dump(stack);
    printf("\n");
    
    int a = link_list_stack_pop(stack);
    printf("pop %d\n", a);
    link_list_dump(stack);
    printf("\n");
    
    int b = link_list_stack_pop(stack);
    printf("pop %d\n", b);
    link_list_dump(stack);
    printf("\n");
    
    int c = link_list_stack_pop(stack);
    printf("pop %d\n", c);
    link_list_dump(stack);
    printf("\n");
    
    return 0;
}

