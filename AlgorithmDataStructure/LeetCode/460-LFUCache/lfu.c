
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/// 方法不好，待完善



typedef struct _lfu_cache_node {
    struct _lfu_cache_node *prev;
    struct _lfu_cache_node *next;
    int key;
    int data;
    int count;
} LFUCacheNode;

typedef struct {
    LFUCacheNode *head;
    LFUCacheNode *tail;
    int capacity;
    int size;
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *cache = (LFUCache *)malloc(sizeof(LFUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->size = 0;
    cache->capacity = capacity;
    return cache;
}

//插入到队列合适的位置，根据出现次数count，确定插入的位置
void lFUCacheInsert(LFUCache *obj, LFUCacheNode *node, int data, int key) {
    if (node == NULL) {
        node = (LFUCacheNode *)malloc(sizeof(LFUCacheNode));
        node->count = 0;
    }
    node->key = key;
    node->data = data;
    node->count += 1;
    node->next = NULL;
    node->prev = NULL;
    
    if (obj->size == 0) {
        obj->head = node;
        obj->tail = node;
    } else {
        //根据出现的次数，来去掉插入的位置，count 从大到小
        LFUCacheNode *tempNode = obj->head;
        if (tempNode->count <= node->count) {
            //插入队头
            node->next = tempNode;
            tempNode->prev = node;
            obj->head = node;
        } else {
            while (tempNode != NULL) {
                if (tempNode->count <= node->count) { break; }
                tempNode = tempNode->next;
            }
            if (tempNode == NULL) {
                //插入队尾
                obj->tail->next = node;
                node->prev = obj->tail;
                obj->tail = node;
            } else {
                tempNode->prev->next = node;
                node->next = tempNode;
                node->prev = tempNode->prev;
                tempNode->prev = node;
            }
        }
    }
    
    obj->size += 1;
}

//移除队尾，最后一个节点
void lFUCacheRemoveTail(LFUCache *obj) {
    if (obj->size <= 0) { return; }
    LFUCacheNode *node = obj->tail;
    if (obj->size > 1) {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
    } else {
        obj->head = NULL;
        obj->tail = NULL;
    }
    obj->size -= 1;
    node->next = NULL; node->prev = NULL;free(node);
}

//移除中间某一个节点
void lFUCacheRemoveNode(LFUCache *obj, LFUCacheNode *node) {
    if (obj == NULL || node == NULL) { return; }
    if (node == obj->head) {
        obj->head = obj->head->next;
    } else if (node == obj->tail) {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    obj->size -= 1;
    node->next = NULL; node->prev = NULL;
    if (obj->size == 0) {
        obj->head = NULL; obj->tail = NULL;
    }
}

//查找
LFUCacheNode *lFUCacheSearch(LFUCache *obj, int key) {
    LFUCacheNode *node = obj->head;
    while (node != NULL) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}



//取出使用某个节点时，如果在链表中找到了，先删除这个节点，然后把这个节点放在头部。
//头部是经常使用的。
int lFUCacheGet(LFUCache* obj, int key) {
    if (obj == NULL || obj->size <= 0) { return -1; }
    LFUCacheNode *node = lFUCacheSearch(obj, key);
    if (node == NULL) {
        return -1;
    } else {
        lFUCacheRemoveNode(obj, node);
        lFUCacheInsert(obj, node, node->data, key);
        return node->data;
    }
}

//插入时，也是先查找，有的话已到队头。没有新建节点插入队头。
//如果达到最大容量时，移除队尾，不经常使用的节点。
void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj == NULL || obj->capacity < 1) { return; }
    LFUCacheNode *node = lFUCacheSearch(obj, key);
    if (node == NULL) {
        if (obj->size >= obj->capacity) { lFUCacheRemoveTail(obj); }
        lFUCacheInsert(obj, NULL, value, key);
    } else {
        lFUCacheRemoveNode(obj, node);
        lFUCacheInsert(obj, node, value, key);
    }
}

void lFUCacheFree(LFUCache* obj) {
    LFUCacheNode *node = NULL;
    while (obj->size > 0) {
        node = obj->head;
        obj->head = obj->head->next;
        free(node);
        obj->size -= 1;
    }
    memset(obj, 0, sizeof(LFUCache));
    free(obj);
}



void lFUCacheDump(LFUCache *obj) {
    LFUCacheNode *node = obj->head;
    while (node != NULL) {
        printf("[%d] = %d %d   %p  %p %p\n", node->key, node->data, node->count,node, node->prev, node->next);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    LFUCache* obj = lFUCacheCreate(0);
    
    lFUCachePut(obj, 0, 0);
    lFUCacheDump(obj);
    printf("----- %d \n", obj->size);
    

    printf("%d\n", lFUCacheGet(obj, 0));
    printf("%d\n", lFUCacheGet(obj, 3));
    printf("%d\n", lFUCacheGet(obj, 4));
    
    
    lFUCacheFree(obj);
    
    return 0;
}




