
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->in_stack = stackCreate();
    q->out_stack = stackCreate();
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->in_stack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->out_stack->next == NULL) {
        while (obj->in_stack->next != NULL) {
            stackPush(obj->out_stack, stackPop(obj->in_stack));
        }
    }
    return stackPop(obj->out_stack);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->out_stack->next == NULL && obj->in_stack->next != NULL) {
        while (obj->in_stack->next != NULL) {
            stackPush(obj->out_stack, stackPop(obj->in_stack));
        }
    }
    
    if (obj->out_stack->next != NULL) {
        return obj->out_stack->next->data;
    } else {
        return -1;
    }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj == NULL || obj->in_stack == NULL || obj->out_stack == NULL) {
        return true;
    }
    return obj->in_stack->next == NULL && obj->out_stack->next == NULL;
}

void myQueueFree(MyQueue* obj) {
    stackDestroy(obj->in_stack);
    stackDestroy(obj->out_stack);
    obj->in_stack = NULL;
    obj->out_stack = NULL;
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main(int argc, const char * argv[]) {
    MyQueue* q = myQueueCreate();
    printf("out - %d\n", myQueuePop(q));
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);
    
    stackDump(q->in_stack); stackDump(q->out_stack);
    printf("\n peek = %d \n", myQueuePeek(q));

    
    printf("out - %d\n", myQueuePop(q));
    stackDump(q->in_stack); stackDump(q->out_stack);
    printf("\n peek = %d \n", myQueuePeek(q));
    
    myQueuePush(q, 4);
    myQueuePush(q, 5);
    
    stackDump(q->in_stack); stackDump(q->out_stack);
    printf("\n peek = %d \n", myQueuePeek(q));
    
    printf("out - %d\n", myQueuePop(q));
    printf("\n peek = %d \n", myQueuePeek(q));
    
    printf("out - %d\n", myQueuePop(q));
    printf("out - %d\n", myQueuePop(q));
    printf("\n peek = %d \n", myQueuePeek(q));
    
    printf("out - %d\n", myQueuePop(q));
    printf("\n peek = %d \n", myQueuePeek(q));
    
    myQueueFree(q);
}



