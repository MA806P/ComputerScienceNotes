//
//  singleList.h
//  CTest
//
//  Created by MA806P on 2019/4/15.
//  Copyright © 2019 myz. All rights reserved.
//

#ifndef singleList_h
#define singleList_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode {
    struct listNode *next;
    void *value;
}listNode;

typedef struct linkedList {
    listNode *head;
    size_t len;
    size_t typesize;
    
    void(*dup)(void*, void*);
    int(*match)(void*, void*);
    void(*free)(void*);
}linkedList;


linkedList *listCreate(void);
void listRelease(linkedList *list);
void listEmpty(linkedList *list);
linkedList *listAddNodeHead(linkedList *list, void *value);
linkedList *listAddNodeTail(linkedList *list, void *value);
linkedList *listInsertNode(linkedList *list, listNode *old_node, void *value, bool after);
void listDelNode(linkedList *list, listNode *node);

listNode *listSearchKey(linkedList *list, void *key);
listNode *listIndex(linkedList *list, long index);
linkedList *listRewind(linkedList *list);

size_t listLength(linkedList *list);


void dump(linkedList *list);

#endif /* singleList_h */
