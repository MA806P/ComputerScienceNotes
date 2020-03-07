
#include <stdio.h>
#include <stdlib.h>

typedef struct _max_queue_node {
    int val;
    struct _max_queue_node *next;
} MaxQueueNode;

typedef struct {
    MaxQueueNode *front;
    MaxQueueNode *back;
    int max_value;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *q = (MaxQueue *)malloc(sizeof(MaxQueue));
    if (q == NULL) { return NULL; }
    q->front = NULL;
    q->back = NULL;
    q->max_value = -1;
    return q;
}

int maxQueueMax_value(MaxQueue* obj) {
    if (obj == NULL) { return -1; }
    return obj->max_value;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if (obj == NULL) { return; }
    
    MaxQueueNode *node = (MaxQueueNode *)malloc(sizeof(MaxQueueNode));
    node->val = value;
    node->next = NULL;
    
    if (value > obj->max_value) {
        obj->max_value = value;
    }
    
    if (obj->front == NULL) {
        obj->front = node;
    } else {
        obj->back->next = node;
    }
    obj->back = node;
    
}

int maxQueuePop_front(MaxQueue* obj) {
    if (obj == NULL || obj->front == NULL) { return -1; }
    
    MaxQueueNode *node = obj->front;
    int data = node->val;
    obj->front = node->next;
    
    
    if (obj->max_value <= data) {
        MaxQueueNode *next = obj->front;
        if (next == NULL) {
            obj->max_value = -1;
        } else {
            int max = -1;
            while (next != NULL) {
                if (max < next->val) {
                    max = next->val;
                }
                next = next->next;
            }
            obj->max_value = max;
        }
    }
    
    free(node);
    return data;
}

void maxQueueFree(MaxQueue* obj) {
    if (obj == NULL) { return; }
    
    while (obj->front != NULL) {
        maxQueuePop_front(obj);
    }
    obj->front = NULL;
    obj->back = NULL;
    free(obj);
}


int main(int argc, const char * argv[]) {
    
    
    MaxQueue* obj = maxQueueCreate();
    int param_1 = maxQueueMax_value(obj);
    
    int param_2 = maxQueuePop_front(obj);
    int param_3 = maxQueuePop_front(obj);
    printf("max = %d  %d %d\n", param_1, param_2, param_3);
    
    maxQueuePush_back(obj, 94);
    maxQueuePush_back(obj, 16);
    maxQueuePush_back(obj, 89);
    
    int param_4 = maxQueuePop_front(obj);
    maxQueuePush_back(obj, 22);
    int param_5 = maxQueuePop_front(obj);
    printf("%d %d\n", param_4, param_5);
    
    maxQueueFree(obj);
    
    return 0;
}




