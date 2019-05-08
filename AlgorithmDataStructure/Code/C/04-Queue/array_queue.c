#include <stdlib.h>
#include <stdio.h>

typedef struct _array_queue{
    int size; //队列大小
    int num; //当前存储数据的大小
    int head; //队列的头
    int tail; //队列的尾
    int *array; //数据存储区
}ArrayQueue;

#define array_queue_is_empty(arrayQueue) (arrayQueue->num == 0)
#define array_queue_is_full(arrayQueue) ((arrayQueue->num) == (arrayQueue->size))

ArrayQueue *array_queue_create(int size) {
    
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    int *array = (int *)malloc(sizeof(int) * size);
    if (array == NULL) {
        free(queue);
        return NULL;
    }
    
    queue->array = array;
    queue->size = size;
    queue->num = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void array_queue_destory(ArrayQueue *queue) {
    if (queue == NULL) {
        return;
    }
    
    if (queue->array != NULL) {
        free(queue->array);
    }
    free(queue);
    return;
}

int array_queue_enqueue(ArrayQueue *queue, int data) {
    if (queue == NULL || array_queue_is_full(queue)) {
        return -1;
    }
    queue->num++;
    queue->array[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
    return 0;
}

int array_queue_dequeue(ArrayQueue *queue, int *data) {
    if (queue == NULL || data == NULL || array_queue_is_empty(queue)) {
        return -1;
    }
    *data = queue->array[queue->head];
    queue->num--;
    queue->head = (queue->head + 1) % queue->size;
    return 0;
}

void array_queue_dump(ArrayQueue *queue) {
    if (queue == NULL || array_queue_is_empty(queue)) {
        printf("\nqueue is empty.\n");
        return;
    }
    
    printf("\nqueue size:%d, num:%d, head:%d, tail:%d\n", queue->size, queue->num, queue->head, queue->tail);
    
    int i = 0;
    int pos = 0;
    for (i = 0; i < queue->num; i++) {
        pos = (queue->head + i) % queue->size;
        printf("array[%d] = %d\n", pos, queue->array[pos]);
    }
    return;
}


int main(int argc, const char * argv[]) {
    
    ArrayQueue *queue = array_queue_create(2);
    array_queue_dump(queue);
    
    array_queue_enqueue(queue, 2);
    array_queue_dump(queue);
    array_queue_enqueue(queue, 3);
    array_queue_dump(queue);
    
    array_queue_enqueue(queue, 4);
    array_queue_dump(queue);
    
    int data = 0;
    array_queue_dequeue(queue, &data);
    array_queue_dump(queue);
    printf("\n --- %d\n", data);
    
    
    return 0;
}



