#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct _node {
    int key;
    int value;
    int max_level; //当前节点最大层数
    struct _node *next[0]; // level层链表结构
}node;

typedef struct _skipList {
    int level;
    int count;
    node *head;
}skipList;


//根据当前结构体元素的地址，获取到结构体首地址
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container(ptr,type,member) ({\
const typeof( ((type *)0)->member) *__mptr = (ptr);\
(type *) ( (char *)__mptr - offsetof(type,member));})


// 创建 node 节点
node *skip_list_create_node(int level, int key, int value) {
    
    node *tmp = (node *)malloc(sizeof(node) + level * sizeof(node *));
    assert(tmp != NULL);
    
    memset(tmp, 0, sizeof(node) + level * sizeof(node *));
    tmp->key = key;
    tmp->value = value;
    tmp->max_level = level;
    
    return tmp;
}

// 创建表头
skipList * skip_list_create(int max_level) {
    
    skipList *list = (skipList *)malloc(sizeof(skipList));
    assert(list != NULL);
    list->level = 1;
    list->count = 0;
    list->head = skip_list_create_node(max_level, 0, 0);
    if (list->head == NULL) {
        free(list);
        return NULL;
    } else {
        return list;
    }
}

// 销毁表
void skip_list_destory(skipList *list) {
    
    if (list == NULL || list->head == NULL) {
        return;
    }
    
    node *tmp = NULL;
    while (list->head->next[0] != NULL) {
        tmp = list->head->next[0];
        list->head->next[0] = tmp->next[0];
        free(tmp);
    }
    
    free(list->head);
    free(list);
    return;
}

// 遍历
void skip_list_dump(skipList *list) {
    
    node *ptmp = NULL;
    int i = 0;
    
    printf("--------------\n");
    printf("skip list level[%d], count[%d]\n", list->level, list->count);
    
    for (i = list->level - 1; i >= 0; i--) {
        ptmp = list->head->next[i];
        printf("level[%d]:", i);
        while (ptmp != NULL) {
            printf("%d - %d\n", ptmp->key, ptmp->value);
            ptmp = ptmp->next[i];
        }
    }
    printf("\r\n--------------\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    return 0;
}

