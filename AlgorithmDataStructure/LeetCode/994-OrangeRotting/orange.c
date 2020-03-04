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
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL) { return -1; }
    
    int cnt = 0; //新鲜橘子的数量
    int dirX[4] = {-1, 0, 1, 0}; //方向上下左右
    int dirY[4] = {0, -1, 0, 1};
    int ans = 0; //结果
    MyQueue *q = myQueueCreate(); //队列用来保存坏橘子的位置
    
    int dis[10][10]; //记录向周围扩散的时间
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            dis[i][j] = -1;
        }
    }
    
    int colSize = gridColSize[0];
    //遍历，记录新鲜橘子的数量和坏橘子的位置
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colSize; j++) {
            printf("%d ", grid[i][j]);
            if (grid[i][j] == 2) {
                myQueuePush(q, i, j);
                dis[i][j] = 0;
            } else if (grid[i][j] == 1) {
                cnt += 1;
            }
        }
        printf("\n");
    }
    printf("\n");
    
    myQueueDump(q);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    
    while (!myQueueEmpty(q)) {
        
        //遍历保存的一开始的所有坏橘子的节点
        MyQueueNode *node = myQueuePop(q);
        int x = node->x, y = node->y;
        free(node);
        
        //处理坏橘子的上下左右的橘子
        for (int i = 0; i < 4; i++) {
            int tx = x + dirX[i], ty = y + dirY[i];
            if (tx < 0 || tx >= gridSize || ty < 0 || ty >= colSize || dis[tx][ty]>=0 || grid[tx][ty]==0) { continue; }
            dis[tx][ty] = dis[x][y] + 1;
            myQueuePush(q, tx, ty);
            if (grid[tx][ty] == 1) {
                //上下左右的好橘子变成了坏橘子
                cnt -= 1;
                ans = dis[tx][ty];
                if (cnt == 0) { break; }
            }
        }
    }
    
    return cnt == 0 ? ans : -1;
}



int main(int argc, const char * argv[]) {
    
    int array[3][3] = {{2,1,1},{1,1,0},{0,1,1}};
    
    int **a = (int **)malloc(sizeof(int *)*3);
    for (int i = 0; i < 3; i++) {
        int *a1 = (int *)malloc(sizeof(int)*3);
        for (int j = 0; j < 3; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[3] = {3};
    printf("= %d\n", orangesRotting(a, 3, b));
    
    return 0;
}

