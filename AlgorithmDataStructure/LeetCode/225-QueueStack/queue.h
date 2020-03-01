
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _queue_node {
    int data;
    struct _queue_node *next;
} QueueNode;

typedef struct _list_queue {
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

#define queue_is_empty(queue) (queue->size == 0)
Queue *queueCreate(void);
int queuePush(Queue *queue, int data);
int queuePop(Queue *queue);
void queueDestroy(Queue *queue);
void queueDump(Queue *queue);


