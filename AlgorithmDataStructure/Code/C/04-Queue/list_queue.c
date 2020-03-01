#include <stdlib.h>
#include <stdio.h>

typedef struct _list_queue_node{
    int data;
    struct _list_queue_node *next;
}ListQueueNode;

typedef struct _list_queue{
    int num;
    ListQueueNode *head;
    ListQueueNode *tail;
}ListQueue;

#define list_queue_is_empty(queue) (queue->num == 0)

ListQueue *list_queue_create() {
    
    ListQueue *queue = (ListQueue *)malloc(sizeof(ListQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->num = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int list_queue_enqueue(ListQueue *queue, int data) {
    if (queue == NULL) {
        return -1;
    }
    ListQueueNode *node = (ListQueueNode *)malloc(sizeof(ListQueueNode));
    if (node == NULL) {
        return -1;
    }
    node->data = data;
    node->next = NULL;
    
    if (queue->head == NULL) {
        queue->head = node;
    } else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->num++;
    return 0;
}

int list_queue_dequeue(ListQueue *queue, int *data) {
    if (queue == NULL || data == NULL || list_queue_is_empty(queue)) {
        return -1;
    }
    *data = queue->head->data;
    ListQueueNode *node = queue->head;
    queue->head = node->next;
    queue->num--;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(node);
    return 0;
}

void list_queue_destory(ListQueue *queue) {
    if (queue == NULL) {
        return;
    }
    if (list_queue_is_empty(queue)) {
        free(queue);
        return;
    }
    
    while (!list_queue_is_empty(queue)) {
        list_queue_dequeue(queue, &data);
    }
    free(queue);
    return;
}

void list_queue_dump(ListQueue *queue) {
    if (queue == NULL || list_queue_is_empty(queue)) {
        printf("\nqueue is empty.\n");
        return;
    }
    
    printf("\nqueue num:%d\n", queue->num);
    
    int i = 0;
    ListQueueNode *node = queue->head;
    while (node != NULL) {
        printf("node[%d] = %d\n", i, node->data);
        i++;
        node = node->next;
    }
    return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    ListQueue *queue = list_queue_create();
    
    list_queue_enqueue(queue, 1);
    list_queue_enqueue(queue, 2);
    list_queue_dump(queue);
    
    int a = -1;
    list_queue_dequeue(queue, &a);
    printf("\ndequeue = %d\n", a);
    list_queue_dump(queue);
    
    list_queue_dequeue(queue, &a);
    printf("\ndequeue = %d\n", a);
    list_queue_dump(queue);
    
    
    return 0;
}



