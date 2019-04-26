//
//  Dlist.c
//  CTest
//
//  Created by MA806P on 2019/4/25.
//  Copyright © 2019 myz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DlistNode {
    struct DlistNode *prev;
    struct DlistNode *next;
    int data;
}stDlistNode;

typedef struct DlistHead {
    stDlistNode *head;
    stDlistNode *tail;
    int size;
}stDlistHead;


void dlist_init(stDlistHead *dlist)
{
    dlist->size = 0;
    dlist->head = NULL;
    dlist->tail = NULL;
    return;
}

void dlist_destory(stDlistHead *dlist)
{
    stDlistNode *pNode = NULL;
    while (dlist->size > 0) {
        pNode = dlist->head;
        dlist->head = dlist->head->next;
        free(pNode);
        dlist->size--;
    }
    memset(dlist, 0, sizeof(stDlistHead)); //置0
}


int dlist_insert_head(stDlistHead *dlist, stDlistNode *pNode, int data)
{
    if (pNode == NULL) {
        pNode = (stDlistNode *)malloc(sizeof(stDlistNode));
        if (pNode == NULL) {
            return -1;
        }
    }
    
    pNode->data = data;
    pNode->prev = NULL;
    pNode->next = NULL;
    
    if (dlist->size == 0) {
        dlist->head = pNode;
        dlist->tail = pNode;
    } else {
        pNode->next = dlist->head;
        dlist->head->prev = pNode;
        dlist->head = pNode;
    }
    dlist->size++;
    
    return 0;
}


stDlistNode * dlist_remove_tail(stDlistHead *dlist)
{
    stDlistNode *pNode = NULL;
    
    if (dlist->size == 0) {
        return NULL;
    }
    
    pNode = dlist->tail;
    if (dlist->size > 1) {
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;
    } else {
        dlist->head = NULL;
        dlist->tail = NULL;
    }
    dlist->size--;
    return pNode;
}

void dlist_remove_node(stDlistHead *dlist, stDlistNode *pNode)
{
    if (dlist == NULL || pNode == NULL) {
        return;
    }
    
    if (pNode == dlist->head) {
        dlist->head = dlist->head->next;
    } else if (pNode == dlist->tail) {
        dlist->tail = dlist->tail->prev;
        dlist->tail->next = NULL;
    } else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }
    
    dlist->size--;
    pNode->prev = NULL;
    pNode->next = NULL;
    
    if (dlist->size == 0) {
        memset(dlist, 0, sizeof(stDlistHead));
    }
    return;
}


stDlistNode * dlist_search(stDlistHead *dlist, int data)
{
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        if (pNode->data == data) {
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}

void dlist_dump(stDlistHead *dlist)
{
    int no = 0;
    stDlistNode *pNode = dlist->head;
    while (pNode != NULL) {
        printf("[%d] = %d\n", no++, pNode->data);
        pNode = pNode->next;
    }
    printf("\n");
    return;
}

//LRU 最近最少使用，缓存淘汰算法
void LRU_dlist(stDlistHead *dlist, int data)
{
    stDlistNode *pNode = NULL;
    //如果在链表中找到这个值，先删除这个节点，然后把这个节点放在头部
    pNode = dlist_search(dlist, data);
    if (pNode != NULL) {
        dlist_remove_node(dlist, pNode);
    } else if (dlist->size >= 4) {
        //在链表中找到，且链表长度大于4，则从链表中删除尾部节点，将新数据放在头部
        pNode = dlist_remove_tail(dlist);
    }
    dlist_insert_head(dlist, pNode, data);
    return;
}

int main() {
    
    stDlistHead dlist = {0};
    
    dlist_init(&dlist);
    dlist_insert_head(&dlist, NULL, 1);
    dlist_insert_head(&dlist, NULL, 2);
    dlist_insert_head(&dlist, NULL, 3);
    dlist_dump(&dlist);
    
    stDlistNode *pNode = NULL;
    pNode = dlist_remove_tail(&dlist);
    if (pNode != NULL) {
        printf("\n remove tail %d\n", pNode->data);
        free(pNode);
    }
    dlist_dump(&dlist);
    
    dlist_insert_head(&dlist, NULL, 4);
    dlist_dump(&dlist);
    
    LRU_dlist(&dlist, 5);
    dlist_dump(&dlist);
    LRU_dlist(&dlist, 6);
    dlist_dump(&dlist);
    LRU_dlist(&dlist, 7);
    dlist_dump(&dlist);
    LRU_dlist(&dlist, 5);
    dlist_dump(&dlist);
    
    dlist_destory(&dlist);
    
    return 0;
}
