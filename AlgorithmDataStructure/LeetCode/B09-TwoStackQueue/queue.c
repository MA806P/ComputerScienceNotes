
#include <stdio.h>
#include <stdlib.h>

typedef int  DATATYPE;
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
        tempS->next = NULL;
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
    if (s->next == NULL) { return -1; }
    stack *next = s->next;
    DATATYPE data = next->data;
    s->next = next->next;
    free(next);
    return data;
}
void stackDump(stack *s) {
    if (s->next == NULL) { printf("stack empty!\n"); return; }
    stack *next = s->next;
    while (next != NULL) {
        printf("-> %d ", next->data);
        next = next->next;
    }
    printf("\n");
}


/**
 1 - e f
 2- d c b a
 
 一个栈负责进，一个栈负责出。当出栈为空时，把进的栈内容倒入出栈中。
 */

typedef struct {
    stack *in_stack;
    stack *out_stack;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *q = (CQueue *)malloc(sizeof(CQueue));
    q->in_stack = stackCreate();
    q->out_stack = stackCreate();
    return q;
}

void cQueueAppendTail(CQueue* obj, int value) {
    stackPush(obj->in_stack, value);
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->out_stack->next == NULL) {
        while (obj->in_stack->next != NULL) {
            stackPush(obj->out_stack, stackPop(obj->in_stack));
        }
    }
    return stackPop(obj->out_stack);
}

void cQueueFree(CQueue* obj) {
    stackDestroy(obj->in_stack);
    stackDestroy(obj->out_stack);
    obj->in_stack = NULL;
    obj->out_stack = NULL;
    free(obj);
}

int main(int argc, const char * argv[]) {
    
    CQueue *q = cQueueCreate();
    printf("out - %d\n", cQueueDeleteHead(q));
    cQueueAppendTail(q, 1);
    cQueueAppendTail(q, 2);
    cQueueAppendTail(q, 3);
    stackDump(q->in_stack); stackDump(q->out_stack);printf("\n");
    printf("out - %d\n", cQueueDeleteHead(q));
    stackDump(q->in_stack); stackDump(q->out_stack);printf("\n");
    cQueueAppendTail(q, 4);
    cQueueAppendTail(q, 5);
    stackDump(q->in_stack); stackDump(q->out_stack);printf("\n");
    printf("out - %d\n", cQueueDeleteHead(q));
    printf("out - %d\n", cQueueDeleteHead(q));
    printf("out - %d\n", cQueueDeleteHead(q));
    printf("out - %d\n", cQueueDeleteHead(q));
    cQueueFree(q);
    
    return 0;
}



