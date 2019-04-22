#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    listNode *next;
    int value;
}listNode;

typedef struct list
{
    listNode *head;
};

bool is_empty(struct list *list)
{
    return list->head == NULL;
}

void dump(struct list *list) 
{
    if (NULL == list)
    {
        return;
    }
    
    listNode *head = list->head;
    int idx = 0;
    while (head)
    {
        printf("[%02d]: %08d\n", idx, head->value);
        idx++;
        head = head->next;
    }
}

void insertNode(listNode **prev, listNode *elem)
{
    if (NULL == prev || NULL == elem)
    {
        return;
    }
    
    if (*prev) {
        elem->next = *prev;
    }
    *prev = elem;
}

void insert_head(struct list *head, listNode *elem) {
    insertNode(&head->head, elem);
}

struct list * delete(listNode **prev)  {
    listNode *tmp;
    
    if (*prev) {
        return NULL;
    }
    
    tmp = *prev;
    *prev = (*prev)->next;
    tmp->next = NULL;
    
    return tmp
}

struct list * delete_head(struct list * head) {
    return delete(&head->head);
}
