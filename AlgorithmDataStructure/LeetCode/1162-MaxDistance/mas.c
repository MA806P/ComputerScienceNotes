

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct my_queue_node {
    int x;
    int y;
    struct my_queue_node *next;
} MyQueueNode;

typedef struct my_queue {
    MyQueueNode *head;
    MyQueueNode *tail;
} MyQueue;

MyQueue *myQueueCreate() {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
void myQueuePush(MyQueue *q, int x, int y) {
    MyQueueNode *node = (MyQueueNode *)malloc(sizeof(MyQueueNode));
    node->x = x; node->y = y; node->next = NULL;
    if (q->head == NULL) {
        q->head = node;
    } else {
        q->tail->next = node;
    }
    q->tail = node;
}
MyQueueNode *myQueuePop(MyQueue *q) {
    if (q->head == NULL) { return NULL; }
    MyQueueNode *node = q->head;
    q->head = node->next;
    node->next = NULL;
    return node;
}
void myQueueDestroy(MyQueue *q) {
    while (q->head != NULL) {
        MyQueueNode *node = q->head;
        q->head = node->next;
        node->next = NULL;
        free(node);
    }
    free(q);
}
bool myQueueEmpty(MyQueue *q) {
    return q->head == NULL;
}
void myQueueDump(MyQueue *q) {
    if (q == NULL || myQueueEmpty(q)) {
        printf("queue is empty!\n");
        return;
    }
    MyQueueNode *node = q->head;
    while (node != NULL) {
        printf("%d  %d\n", node->x, node->y);
        node = node->next;
    }
    printf("end!\n");
}


int maxDistance(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL ) { return 0; }
    
    int dirX[] = {0,1,0,-1};
    int dirY[] = {1,0,-1,0};
    
    MyQueue *q = myQueueCreate();
    //先把所有的陆地都入队
    int colSize = gridColSize[0];
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (grid[i][j] == 1) {
                myQueuePush(q, i, j);
            }
        }
    }
    
    //从陆地开始，一层层的遍历海洋
    int hasOcean = 0;
    int pointI = -1, pointJ = -1;
    while (!myQueueEmpty(q)) {
        MyQueueNode *node = myQueuePop(q);
        pointI = node->x; pointJ = node->y;
        for (int i = 0; i < 4; i++) {
            int nextX = pointI + dirX[i], nextY = pointJ + dirY[i];
            if (nextX < 0 || nextY < 0 || nextX >= gridSize || nextY >= colSize || grid[nextX][nextY]!=0) {
                continue;
            }
            
            grid[nextX][nextY] = grid[pointI][pointJ] + 1;
            hasOcean = 1;
            myQueuePush(q, nextX, nextY);
        }
    }
    myQueueDestroy(q);
    
    //全部都是海洋，或者全部都是陆地
    if (pointI == -1 || hasOcean == 0) { return -1; }
    //返回最后一次遍历到的海洋距离
    return grid[pointI][pointJ] - 1;
}





int main(int argc, const char * argv[]) {
    
    int array[5][5] = {{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    
    int **a = (int **)malloc(sizeof(int *)*5);
    for (int i = 0; i < 5; i++) {
        int *a1 = (int *)malloc(sizeof(int)*5);
        for (int j = 0; j < 5; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[5] = {5,5,5,5,5};
    printf("BFS = %d\n", maxDistance(a, 5, b));
    
    return 0;
}




