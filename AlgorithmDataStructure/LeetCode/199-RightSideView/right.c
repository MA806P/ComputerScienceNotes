

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





int* rightSideView(struct TreeNode* root, int* returnSize){
    
    *returnSize = 0;
    int *ans = (int *)malloc(sizeof(int) * 100);
    if (root == NULL) { return ans; }
    
    //广度优先遍历 BFS
    MQueue *q = m_queueCreate();
    m_queuePush(q, root);
    
    while (!queue_is_empty(q)) {
        int size = q->size;
        //遍历每一层，然后每一层的最右一个保存在队列中
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = m_queuePop(q);
            if (node->left != NULL) { m_queuePush(q, node->left); }
            if (node->right != NULL) { m_queuePush(q, node->right); }
            //每一层的最右节点，最后入队列，所以最后一个就是
            if (i == size - 1) { ans[(*returnSize)] = node->val; *returnSize += 1; }
        }
    }
    m_queueDestroy(q);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode r1 = {9, NULL, NULL};
    struct TreeNode l1 = {7, NULL, NULL};
    struct TreeNode left = {6, &l1, NULL};
    struct TreeNode right = {5, NULL, &r1};
    
    struct TreeNode t1 = {1, &left, &right};
    
    
    int n = 0;
    int *a = rightSideView(&t1, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}








