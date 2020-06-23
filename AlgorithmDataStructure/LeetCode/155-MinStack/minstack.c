
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647


//辅助栈，用两个栈，一个用来存数据，一个用来获取栈最小值
//c 没有栈的实现，就自己实现了栈

typedef struct _stack_node {
    int val;
    struct _stack_node *next;
} MinStackNode;

typedef struct {
    MinStackNode *top;
    MinStackNode *helper;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->top = NULL;
    stack->helper = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj == NULL) { return; }
    MinStackNode *node = (MinStackNode *)malloc(sizeof(MinStackNode));
    node->val = x;
    node->next = obj->top;
    obj->top = node;
    
    MinStackNode *node0 = (MinStackNode *)malloc(sizeof(MinStackNode));
    if (obj->helper == NULL || obj->helper->val >= x) {
        node0->val = x;
    } else {
        node0->val = obj->helper->val;
    }
    node0->next = obj->helper;
    obj->helper = node0;
    
}

void minStackPop(MinStack* obj) {
    if (obj == NULL || obj->top == NULL) { return; }
    MinStackNode *node = obj->top;
    obj->top = node->next;
    free(node);
    
    if (obj->helper == NULL) { return; }
    MinStackNode *node0 = obj->helper;
    obj->helper = node0->next;
    free(node0);
}

int minStackTop(MinStack* obj) {
    if (obj == NULL || obj->top == NULL) { return -1; }
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    if (obj == NULL || obj->helper == NULL) { return -1; }
    return obj->helper->val;
}

void minStackFree(MinStack* obj) {
    if (obj == NULL) { return; }
    while (obj->top != NULL) {
        minStackPop(obj);
    }
    free(obj);
}

void minStackDump(MinStack* obj) {
    if (obj == NULL || obj->top == NULL) {
        printf("stack empty ! \n");
        return;
    }
    MinStackNode *node = obj->top;
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("|| helper - ");
    MinStackNode *node0 = obj->helper;
    while (node0 != NULL) {
        printf("%d -> ", node0->val);
        node0 = node0->next;
    }
    printf(" min = %d, top = %d \n", minStackGetMin(obj), minStackTop(obj));
}

int main(int argc, const char * argv[]) {
    
    MinStack *stack = minStackCreate();
    minStackDump(stack);
    minStackPop(stack);
    minStackDump(stack);
    
    minStackPush(stack, 3);
    minStackDump(stack);
    
    minStackPush(stack, -1);
    minStackDump(stack);
    
    minStackPush(stack, 1);
    minStackDump(stack);
    
    minStackPop(stack);
    minStackPop(stack);
    minStackDump(stack);
    
    minStackFree(stack);
    
    return 0;
}



