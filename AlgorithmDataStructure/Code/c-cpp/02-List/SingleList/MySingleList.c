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

void insertNode(listNode *pre, listNode *elem) 
{
    if (NULL == pre || NULL == elem)
    {
        return;
    }

    elem->next = pre->next;
    pre->next = elem;
}

void deleteNode(struct list *) 
{
    
}
