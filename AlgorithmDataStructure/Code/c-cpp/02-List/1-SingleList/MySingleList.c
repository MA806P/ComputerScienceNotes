#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode
{
    struct listNode *next;
    int value;
};

struct list
{
    struct listNode *head;
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
    
    struct listNode *head = list->head;
    int idx = 0;
    while (head)
    {
        printf("[%02d]: %08d\n", idx, head->value);
        idx++;
        head = head->next;
    }
}

void insertNode(struct listNode **prev, struct listNode *elem)
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

void insert_head(struct list *head, struct listNode *elem) {
    insertNode(&head->head, elem);
}

struct listNode * delete(struct listNode **prev)
{
    struct listNode *tmp;
    
    if (!prev) {
        return NULL;
    }
    
    tmp = *prev;
    *prev = (*prev)->next;
    tmp->next = NULL;
    
    return tmp;
}

struct listNode * delete_head(struct list * head) {
    return delete(&head->head);
}

struct listNode ** search(struct list * head, int target)
{
    struct listNode **prev, *tmp;
    
    prev = &head->head;
    tmp = *prev;
    while ( tmp && (tmp->value < target))
    {
        prev = &tmp->next;
        tmp = *prev;
    }
    return prev;
    
//    for (prev = &head->head, tmp = *prev;
//         tmp && (tmp->value < target);
//         prev = &tmp->next, tmp = *prev)
//        ;
//
//    return prev;
    
}

void reverse(struct list *head)
{
    struct list tmp = { NULL };
    struct listNode *elem;
    
    while (!is_empty(head)) {
        elem = delete_head(head);
        insert_head(&tmp, elem);
    }
    head->head = tmp.head;
}

bool is_cyclic(struct list *head)
{
    struct listNode *s1, *s2;
    
    s1 = s2 = head->head;
    
    while (s1 && s2) {
        s1 = s1->next;
        s2 = s2->next ? s2->next->next : s2->next;
        
        if (s1 == s2) {
            return true;
        }
    }
    
    return false;
}

struct listNode * middle(struct list *head)
{
    struct listNode *s1, *s2;
    struct listNode pseudo_head;
    
    pseudo_head.next = head->head;
    s1 = s2 = &pseudo_head;
    
    while (true) {
        if (!s2 || !s2->next) {
            return s1;
        }
        s1 = s1->next;
        s2 = s2->next->next;
    }
    return NULL;
}


int main()
{
    struct list head = {NULL};
    
    struct listNode nodes[10];
    int idx = 0;
    for (idx = 0; idx < 10; idx++) {
        nodes[idx].value = idx;
        nodes[idx].next = NULL;
    }
    
    insert_head(&head, &nodes[3]);
    insert_head(&head, &nodes[2]);
    insert_head(&head, &nodes[1]);
    insert_head(&head, &nodes[0]);
    dump(&head);
    
    struct listNode **prev;
    prev = search(&head, 2);
    printf("%d\n", (*prev)->value);
    
//    insertNode(prev, &nodes[3]);
//    dump(&head);
    
    
    return 0;
}
