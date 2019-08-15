#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<assert.h>

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

/*
 //根据当前结构体元素的地址，获取到结构体首地址
 #define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
 #define container(ptr,type,member) ({\
 const typeof( ((type *)0)->member) *__mptr = (ptr);\
 (type *) ( (char *)__mptr - offsetof(type,member));})
 */

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


//插入元素获得随机产生层数
int skip_list_level(skipList *list) {
    int level = 1, i = 0;
    for (i = 1; i < list->head->max_level; i++) {
        if (rand()%2 == 1) {
            level++;
        }
    }
    return level;
}

// 插入
int skip_list_insert(skipList *list, int key, int value) {
    
    if (list == NULL) {
        return 1;
    }
    
    //用来更新每层的指针，申请 update 空间用于保存每层的指针
    node **update = (node **)malloc(sizeof(node *)*list->head->max_level);
    if (update == NULL) {
        return 2;
    }
    
    int i = 0;
    
    //逐层查询节点
    node *prev = list->head;
    node *tmp = NULL;
    for (i = list->level - 1; i >= 0; i--) {
        //初始化每 level 层的头指针
        tmp = prev->next[i];
        while (tmp != NULL && tmp->key < key) {
            prev = tmp;
        }
        update[i] = prev;
    }
    
    //当前key已经存在，返回错误
    if (tmp != NULL && tmp->key == key) {
        return 3;
    }
    
    int level = 0;
    //获取元素的随机层数，并更新跳表的最大层数
    level = skip_list_level(list);
    //创建当前数据节点
    tmp = skip_list_create_node(level, key, value);
    if (tmp == NULL) {
        return 4;
    }
    
    //更新最大层数
    if (level > list->level) {
        for (i = list->level; i < level; i++) {
            update[i] = list->head;
        }
        list->level = level;
    }
    
    //逐层更新节点的指针
    for (i = 0; i < level; i++) {
        tmp->next[i] = update[i]->next[i];
        update[i]->next[i] = tmp;
    }
    list->count++;
    
    return 0;
}



int skip_list_delete(skipList * list, int key ,int *value)
{
    int i = 0;
    node **update = NULL;/*用来更新每层的指针*/
    node *tmp = NULL;
    node *prev = NULL;
    
    if ((list == NULL) && (value == NULL)&& (list->count == 0))
    {
        return 1;
    }
    /*申请update空间用于保存每层的指针*/
    update = (node **)malloc(sizeof(node *)*list->level);
    if (update == NULL)
    {
        return 2;
    }
    /*逐层查询节点的*/
    prev = list->head;
    for (i = (list->level -1); i >= 0; i--)
    {
        /*初始化每level层的头指针*/
        while(((tmp = prev->next[i]) != NULL) && (tmp->key < key))
        {
            prev = tmp;
        }
        update[i] = prev;
    }
    
    if ((tmp != NULL)
        && (tmp->key == key))
    {
        *value = tmp->value;
        /*逐层删除*/
        for(i = 0; i < list->level; i++)
        {
            if(update[i]->next[i] == tmp)
            {
                update[i]->next[i] = tmp->next[i];
            }
        }
        
        free(tmp);
        tmp = NULL;
        
        /*更新level的层数*/
        for (i = list->level - 1; i >= 0; i++)
        {
            if (list->head->next[i] == NULL )
            {
                list->level--;
            }
            else
            {
                break;
            }
        }
        
        list->count--;
        
    }
    else
    {
        return 3;/*未找到节点*/
    }
    
    return 0 ;
}

/*查询当前key是否在跳表中，如果存在返回查询的value数值，不存在返回-1*/
int skip_list_search(skipList *list,int key,int *value)
{
    int i = 0;
    node *prev = NULL;
    node *tmp = NULL;
    
    if((list == NULL) || (list->count == 0) || (value == NULL))
    {
        return 1;
    }
    prev = list->head;
    for(i = list->level - 1; i >= 0; i--)
    {
        while(((tmp = prev->next[i]) != NULL) && (tmp->key <= key))
        {
            if (tmp->key == key)
            {
                *value = tmp->value;
                return 0;
            }
            prev = tmp;
        }
    }
    
    return -1;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    skipList *list = skip_list_create(5);
    assert(list != NULL);
    
    
    int res = 0;
    int key = 0;
    int value = 0;
    
    while(1)
    {
        printf("\r\n 请输入key 和 value，当key = 1000时，退出输入：");
        scanf("%d%d",&key,&value);
        if (key == 1000)
        {
            break;
        }
        res = skip_list_insert(list,key,value);
        if (res != 0)
        {
            printf("\r\n skip list insert %d,failed,res=%d.",key,res);
        }
    }
    skip_list_dump(list);
    
    
    while(1)
    {
        printf("\r\n 通过key 查询value的数值，当key = 1000时，退出查询");
        scanf("%d",&key);
        if(key == 1000)
        {
            break;
        }
        res = skip_list_search(list,key,&value);
        if (res != 0)
        {
            printf("\r\n skip list search %d,failed,res=%d.",key,res);
        }
        else
        {
            printf("\r\n skip list search %d,sucessful,value=%d.",key,value);
            
        }
    }
    skip_list_dump(list);
    
    
    while(1)
    {
        printf("\r\n 通过key 删除节点，当key = 1000时，退出删除");
        scanf("%d",&key);
        if(key == 1000)
        {
            break;
        }
        res = skip_list_delete(list,key,&value);
        if (res != 0)
        {
            printf("\r\n skip list search %d,failed,res=%d.",key,res);
        }
        else
        {
            printf("\r\n skip list search %d,sucessful,value=%d.",key,value);
            
        }
    }
    
    skip_list_dump(list);
    skip_list_destory(list);
    
    
    return 0;
}


