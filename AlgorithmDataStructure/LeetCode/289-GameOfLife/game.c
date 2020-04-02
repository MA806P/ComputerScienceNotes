

#include <stdio.h>
#include <stdlib.h>

typedef struct DataType  DATATYPE;
struct DataType {
    int x;
    int y;
    int val;
};
typedef struct _list_stack {
    DATATYPE data;
    int count;
    struct _list_stack *next;
} stack;
stack *stackCreate() {
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) { return NULL; }
    s->next = NULL;
    s->count = 0;
    return s;
}
void stackDestroy(stack *s) {
    stack *tempS = NULL;
    while (s->next != NULL) {
        tempS = s->next;
        s->next = tempS->next;
        free(tempS);
    }
    free(s);
}
void stackPush(stack *s, DATATYPE data) {
    stack *node = (stack *)malloc(sizeof(stack));
    if (node == NULL) { return; }
    s->count += 1;
    node->data = data;
    node->count = s->count;
    node->next = s->next;
    s->next = node;
}
DATATYPE stackPop(stack *s) {
    if (s->next == NULL) {
        DATATYPE data = {0,0,0};
        return data;
    }
    stack *next = s->next;
    DATATYPE data = next->data;
    s->count -= 1;
    s->next = next->next;
    free(next);
    return data;
}
void stackDump(stack *s) {
    if (s->next == NULL) { printf("stack empty!\n"); return; }
    stack *next = s->next;
    while (next != NULL) {
        printf("-> (%d,%d=%d) ", next->data.x, next->data.y,next->data.val);
        next = next->next;
    }
    printf("\n");
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize <= 0 || boardColSize == NULL ) { return; }
    
    int dirX[] = {0,1,0,-1,-1,-1,1,1};
    int dirY[] = {1,0,-1,0,-1,1,-1,1};
    
    stack *s = stackCreate();
    int nearX = 0, nearY = 0, nearLiveCount = 0;
    int colSize = boardColSize[0];
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < colSize; j++) {
            nearLiveCount = 0;
            for (int d = 0; d < 8; d++) {
                nearX = i + dirX[d]; nearY = j + dirY[d];
                if (nearX >= 0 && nearY >= 0 && nearX < boardSize && nearY < colSize && board[nearX][nearY] == 1) {
                    nearLiveCount++;
                }
            }
            
            //把有变动的，入栈保存
            DATATYPE data = {i,j,0};
            if (nearLiveCount < 2 || nearLiveCount > 3) {
                //周围活细胞数少于两个，则该位置活细胞死亡
                //周围有超过三个活细胞，则该位置活细胞死亡
                data.val = 0;
                stackPush(s, data);
            } else if (nearLiveCount == 3 && board[i][j] == 0) {
                //周围正好有三个活细胞，则该位置死细胞复活
                data.val = 1;
                stackPush(s, data);
            }
            //else if ( (nearLiveCount == 2 || nearLiveCount == 3) && board[i][j] == 1) {
                // //周围有两个或三个活细胞，则该位置活细胞仍然存活
                //data.val = 1; stackPush(s, data); }
            
        }
    }
    
    //修改原数据
    if (s->next == NULL) { return; }
    stack *next = s->next;
    while (next != NULL) {
        board[next->data.x][next->data.y] = next->data.val;
        next = next->next;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int array[5][5] = {{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    int **a = (int **)malloc(sizeof(int *)*5);
    for (int i = 0; i < 5; i++) {
        int *a1 = (int *)malloc(sizeof(int)*5);
        for (int j = 0; j < 5; j++) {
            a1[j] = array[i][j];
        }
        a[i] = a1;
    }
    int b[5] = {5,5,5,5,5};
    gameOfLife(a, 5, b);
    
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}




