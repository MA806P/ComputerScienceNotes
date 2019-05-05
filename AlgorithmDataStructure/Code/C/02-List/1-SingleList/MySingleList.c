#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode
{
    int value;
    struct listNode *next;
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
    
    //printf("--- %p=%p  %p=%p\n", &list, list, &(list->head), list->head);
    
    int idx = 0;
    while (head)
    {
        printf("[%02d]: %02d %p=%p %p %p %p\n", idx, head->value, &head, head, &(head->value), &(head->next), head->next);
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
    //printf("\n search \n");
    
    struct listNode **prev, *tmp;
    
    prev = &head->head;
    tmp = *prev;
    while ( tmp && (tmp->value < target))
    {
        //printf("%p=%p %p=%p %p=%p \n", &prev, prev, &(*prev), (*prev), &tmp, tmp);
        prev = &tmp->next;
        tmp = *prev;
    }
    
    //printf("search end \n");
    
    return prev;
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
        printf("%p\n", &(nodes[idx]));
    }
    
    insert_head(&head, &nodes[6]);
    insert_head(&head, &nodes[5]);
    insert_head(&head, &nodes[1]);
    insert_head(&head, &nodes[0]);
    dump(&head);
    
    struct listNode **prev;
    prev = search(&head, 2);
    printf("%d\n", (*prev)->value);
    
    insertNode(prev, &nodes[3]);
    dump(&head);
    
    
    printf("\n**********************\n");
    
    printf("middle elem is %d\n", middle(&head)->value);
    
    prev = search(&head, 5);
    if ((*prev) && ((*prev)->value == 5)) {
        printf("contain\n");
    } else {
        printf("not contain\n");
    }
    
    delete(prev);
    prev = search(&head, 5);
    if ((*prev) && ((*prev)->value == 5)) {
        printf("contain\n");
    } else {
        printf("not contain\n");
    }
    dump(&head);
    
    
    printf("\n**********************\n");
    
    printf("\n After reverse \n");
    reverse(&head);
    dump(&head);
    printf("\n middle elem is %d\n", middle(&head)->value);
    
    printf("list is %s cyclic\n", is_cyclic(&head) ? "" : "not");
    
    nodes[0].next = &nodes[6];
    printf("list is %s cyclic\n", is_cyclic(&head) ? "" : "not");
    
    
    return 0;
}

/*
 
 0x7ffee2421a80
 0x7ffee2421a90
 0x7ffee2421aa0
 0x7ffee2421ab0
 0x7ffee2421ac0
 0x7ffee2421ad0
 0x7ffee2421ae0
 0x7ffee2421af0
 0x7ffee2421b00
 0x7ffee2421b10
 [00]: 00 0x7ffee2421a00=0x7ffee2421a80 0x7ffee2421a80 0x7ffee2421a88 0x7ffee2421a90
 [01]: 01 0x7ffee2421a00=0x7ffee2421a90 0x7ffee2421a90 0x7ffee2421a98 0x7ffee2421ad0
 [02]: 05 0x7ffee2421a00=0x7ffee2421ad0 0x7ffee2421ad0 0x7ffee2421ad8 0x7ffee2421ae0
 [03]: 06 0x7ffee2421a00=0x7ffee2421ae0 0x7ffee2421ae0 0x7ffee2421ae8 0x0
 5
 [00]: 00 0x7ffee2421a00=0x7ffee2421a80 0x7ffee2421a80 0x7ffee2421a88 0x7ffee2421a90
 [01]: 01 0x7ffee2421a00=0x7ffee2421a90 0x7ffee2421a90 0x7ffee2421a98 0x7ffee2421ab0
 [02]: 03 0x7ffee2421a00=0x7ffee2421ab0 0x7ffee2421ab0 0x7ffee2421ab8 0x7ffee2421ad0
 [03]: 05 0x7ffee2421a00=0x7ffee2421ad0 0x7ffee2421ad0 0x7ffee2421ad8 0x7ffee2421ae0
 [04]: 06 0x7ffee2421a00=0x7ffee2421ae0 0x7ffee2421ae0 0x7ffee2421ae8 0x0
 
 **********************
 middle elem is 3
 contain
 not contain
 [00]: 00 0x7ffee2421a00=0x7ffee2421a80 0x7ffee2421a80 0x7ffee2421a88 0x7ffee2421a90
 [01]: 01 0x7ffee2421a00=0x7ffee2421a90 0x7ffee2421a90 0x7ffee2421a98 0x7ffee2421ab0
 [02]: 03 0x7ffee2421a00=0x7ffee2421ab0 0x7ffee2421ab0 0x7ffee2421ab8 0x7ffee2421ae0
 [03]: 06 0x7ffee2421a00=0x7ffee2421ae0 0x7ffee2421ae0 0x7ffee2421ae8 0x0
 
 **********************
 
 After reverse
 [00]: 06 0x7ffee2421a00=0x7ffee2421ae0 0x7ffee2421ae0 0x7ffee2421ae8 0x7ffee2421ab0
 [01]: 03 0x7ffee2421a00=0x7ffee2421ab0 0x7ffee2421ab0 0x7ffee2421ab8 0x7ffee2421a90
 [02]: 01 0x7ffee2421a00=0x7ffee2421a90 0x7ffee2421a90 0x7ffee2421a98 0x7ffee2421a80
 [03]: 00 0x7ffee2421a00=0x7ffee2421a80 0x7ffee2421a80 0x7ffee2421a88 0x0
 
 middle elem is 3
 list is not cyclic
 list is  cyclic

 
 */
