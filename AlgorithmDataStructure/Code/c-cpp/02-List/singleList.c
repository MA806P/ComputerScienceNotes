//
//  singleList.c
//  CTest
//
//  Created by MA806P on 2019/4/15.
//  Copyright © 2019 myz. All rights reserved.
//

#include "singleList.h"
#include <stdio.h>

linkedList *listCreate(void) {
    linkedList *list = NULL;
    list = malloc(sizeof(*list));
    if (NULL == list) {
        return NULL;
    }
    
    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;
    
    list->head = NULL;
    list->len = 0;
    list->typesize = 0;
    
    return list;
}


void listRelease(linkedList *list) {
    if (NULL == list) {
        return;
    }
    listEmpty(list);
    free(list);
    list = NULL;
}

void listEmpty(linkedList *list) {
    if (NULL == list) {
        return;
    }
    
    while (NULL != list->head) {
        listNode *pNode = list->head;
        list->head = pNode->next;
        if (NULL != list->free) {
            list->free(pNode->value);
        }
        
        pNode->next = NULL;
        free(pNode);
        pNode = NULL;
    }
}


linkedList *listAddNodeHead(linkedList *list, void *value) {
    if (NULL == list || NULL == value) {
        return list;
    }
    
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node) {
        return list;
    }
    
    node->value = value;
    node->next = list->head;
    list->head = node;
    
    list->len += 1;
    return list;
}
linkedList *listAddNodeTail(linkedList *list, void *value) {
    if (NULL == list || NULL == value) {
        return list;
    }
    
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node) {
        return list;
    }
    node->value = value;
    node->next = NULL;
    
    if (NULL == list->head && list->len == 0) {
        list->head = node;
    } else {
        listNode *tail = list->head;
        listNode *pre = list->head;
        while (NULL != tail) {
            pre = tail;
            tail = tail->next;
        }
        pre->next = node;
    }
    
    list->len += 1;
    return list;
}

linkedList *listInsertNode(linkedList *list, listNode *old_node, void *value, bool after) {
    if (NULL == list || NULL == value) {
        return list;
    }
    
    listNode *node = NULL;
    node = malloc(sizeof(*node));
    if (NULL == node) {
        return list;
    }
    node->value = value;
    
    if (after) {
        node->next = old_node->next;
        old_node->next =  node;
    } else {
        listNode *pre = list->head;
        while (NULL != pre && pre->next != old_node) {
            pre = pre->next;
        }
        
        if (NULL != pre) {
            pre->next = node;
            node->next = old_node;
        }
    }
    
    list->len += 1;
    return list;
}
void listDelNode(linkedList *list, listNode *node) {
    if (NULL == list || NULL == node) {
        return;
    }
    
    listNode *pre = list->head;
    listNode *cur = list->head;
    while (NULL != cur && cur != node) {
        pre = cur;
        cur = cur->next;
    }
    
    if (NULL == pre) {
        return;
    }
    
    pre->next = node->next;
    node->next = NULL;
    --list->len;
    
    if (NULL != list->free) {
        list->free(node->value);
    }
    free(node);
    node = NULL;
}

listNode *listSearchKey(linkedList *list, void *key) {
    if (NULL == list) {
        return NULL;
    }
    
    listNode *node = list->head;
    while (NULL != node) {
        if (NULL != list->match) {
            if (list->match(key, node->value) == 0) {
                return node;
            }
        } else {
            if (key == node->value) {
                return node;
            }
        }
        node = node->next;
    }
    return NULL;
}
listNode *listIndex(linkedList *list, long index) {
    if (NULL == list || index <= 0 || index > list->len) {
        return NULL;
    }
    
    listNode *node = list->head;
    for (long i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}
linkedList *listRewind(linkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    listNode *head = list->head;
    listNode *pre = NULL;
    listNode *next = NULL;
    while (NULL != head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    list->head = pre;
    return list;
}

size_t listLength(linkedList *list) {
    if (NULL == list) {
        return 0;
    }
    return list->len;
}


void dump(linkedList *list) {
    if (NULL == list) {
        return;
    }
    
    listNode *tmp = list->head;
    int idx = 0;
    while (tmp) {
        int *tmpValue = tmp->value;
        printf("[%02d]: %02d\n", idx, *tmpValue);
        tmp = tmp->next;
        idx++;
    }
}
