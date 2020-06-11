

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



typedef struct TreeNode *  DATATYPE;

typedef struct m_queue_node {
    DATATYPE data;
    struct m_queue_node *next;
} MQueueNode;

typedef struct m_list_queue {
    int size;
    MQueueNode *head;
    MQueueNode *tail;
} MQueue;

#define queue_is_empty(queue) (queue->size == 0)

MQueue *m_queueCreate(void) {
    MQueue *queue = (MQueue *)malloc(sizeof(MQueue));
    if (queue == NULL) { return NULL; }
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int m_queuePush(MQueue *queue, DATATYPE data) {
    if (queue == NULL) { return -1; }
    MQueueNode *node = (MQueueNode *)malloc(sizeof(MQueueNode));
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

DATATYPE m_queuePop(MQueue *queue) {
    if (queue == NULL || queue_is_empty(queue)) { return NULL; }
    MQueueNode *node = queue->head;
    DATATYPE data = node->data;
    queue->head = node->next;
    queue->size -= 1;
    if (queue->head == NULL) { queue->tail = NULL; }
    free(node);
    return data;
}

void m_queueDestroy(MQueue *queue) {
    if (queue == NULL) { return; }
    if (queue_is_empty(queue)) { free(queue); return; }
    while (!queue_is_empty(queue)) { m_queuePop(queue); }
    free(queue);
}




#define MAX_LEVEL 100


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    *returnSize = 0;
    int **ans = (int **)malloc(sizeof(int *) * MAX_LEVEL);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_LEVEL);
    if (root == NULL) { return ans; }
    
    //广度优先遍历 BFS
    MQueue *q = m_queueCreate();
    m_queuePush(q, root);
    
    while (!queue_is_empty(q)) {
        int size = q->size;
        int *returnColum = (int *)malloc(sizeof(int) * size);
        
        //遍历每一层
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = m_queuePop(q); //出队列
            returnColum[i] = node->val;
            //左右子树入队列。注意左右顺序，先左后右
            if (node->left != NULL) { m_queuePush(q, node->left); }
            if (node->right != NULL) { m_queuePush(q, node->right); }
        }
        //每一层遍历完毕，将数组放入大数组中
        (*returnColumnSizes)[(*returnSize)] = size;
        ans[(*returnSize)] = returnColum;
        (*returnSize) += 1;
    }
    
    
    
    return ans;
}



int main(int argc, const char * argv[]) {
    
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {4, NULL, NULL};
    struct TreeNode n22 = {5, NULL, NULL};
    struct TreeNode n2 = {6, &n21, &n22};
    
    struct TreeNode n = {7, &n1, &n2};
    
    int returnSize = 0;
    int *returnColumnSizes;
    
    int **ans = levelOrder(&n, &returnSize, &returnColumnSizes);
    printf("tree level = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        int levelSize = returnColumnSizes[i];
        printf("%d level[%d] =  ", i, levelSize);
        for (int j = 0; j < levelSize; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}



