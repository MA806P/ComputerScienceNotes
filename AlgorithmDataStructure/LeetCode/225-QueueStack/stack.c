
#include "queue.h"

typedef struct {
    Queue *a;
    Queue *b;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack == NULL) { return NULL; }
    stack->a = queueCreate(); //保存数据
    stack->b = queueCreate(); //辅助队列
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj == NULL) { return; }
    queuePush(obj->a, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj == NULL || queue_is_empty(obj->a)) { return -1; }
    //把 a 中的数据先保存到 b 中，a 只留一个出栈
    //然后交换 a b
    while (obj->a->size > 1) {
        queuePush(obj->b, queuePop(obj->a));
    }
    int data = queuePop(obj->a);
    Queue *queue = obj->b;
    obj->b = obj->a;
    obj->a = queue;
    return data;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj == NULL || queue_is_empty(obj->a)) { return -1; }
    return obj->a->tail->data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj == NULL) { return true; }
    return queue_is_empty(obj->a);
}

void myStackFree(MyStack* obj) {
    queueDestroy(obj->a);
    queueDestroy(obj->b);
    free(obj);
}



int main(int argc, const char * argv[]) {
    
    MyStack* obj = myStackCreate();
    myStackPush(obj, 2);
    myStackPush(obj, 3);
    
    int param_2 = myStackPop(obj);
    printf("%d\n", param_2); //3
    
    int param_3 = myStackTop(obj);
    printf("%d\n", param_3); //2
    
    bool param_4 = myStackEmpty(obj);
    printf("%d\n", param_4); //0
    
    myStackFree(obj);
    
    
    printf("------------- queue ----------\n");
    Queue *queue = queueCreate();
    
    queuePush(queue, 101);
    queuePush(queue, 102);
    queueDump(queue);
    
    int a = queuePop(queue);
    printf("out = %d\n", a);
    queueDump(queue);
    
    a = queuePop(queue);
    printf("out = %d\n", a);
    queueDump(queue);
    
    return 0;
}












