
#include "queue.h"

Queue *queueCreate(void) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) { return NULL; }
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}
int queuePush(Queue *queue, int data) {
    if (queue == NULL) { return -1; }
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL) { return -1; }
    node->data = data;
    node->next = NULL;
    if (queue_is_empty(queue)) {
        queue->head = node;
    } else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->size += 1;
    return 0;
}

int queuePop(Queue *queue) {
    if (queue == NULL || queue_is_empty(queue)) { return -1; }
    QueueNode *node = queue->head;
    int data = node->data;
    queue->head = node->next;
    queue->size -= 1;
    if (queue->head == NULL) { queue->tail = NULL; }
    free(node);
    return data;
}

void queueDestroy(Queue *queue) {
    if (queue == NULL) { return; }
    if (queue_is_empty(queue)) { free(queue); return; }
    while (!queue_is_empty(queue)) { queuePop(queue); }
    free(queue);
}

void queueDump(Queue *queue) {
    if (queue == NULL || queue_is_empty(queue)) {
        printf("queue is empty!\n");
        return;
    }
    QueueNode *node = queue->head;
    while (node != NULL) {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

